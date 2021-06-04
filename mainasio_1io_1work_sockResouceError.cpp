//
// async_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <thread>
#include <poll.h>

#include <unistd.h>
#include <sys/syscall.h>

#include "asio.hpp"

using asio::ip::tcp;

class session
  : public std::enable_shared_from_this<session>
{
public:
  session(tcp::socket socket)
    : socket_(std::move(socket))
  {
  }
  
  ~session(void)
  {
    printf("Session %p has be Delete.. socket:%p\n",this,&socket_);
  }

  void start()
  {
    do_read();
  }

private:
  void do_read()
  {
    auto self(shared_from_this()); 
    printf("do_read %p share count:%td tid:%td\n",&socket_,self.use_count(),syscall(SYS_gettid));
    socket_.async_read_some(asio::buffer(data_, max_length),
        [self,this](std::error_code ec, std::size_t length)
        {
          if (!ec)
          {
            printf("read %s len:%td\n",data_,length);
            do_write(length);
          }
        });
  }

  void do_write(std::size_t length)
  {
    auto self(shared_from_this());
    asio::async_write(socket_, asio::buffer(data/*, length*/),
        [self,this](std::error_code ec, std::size_t tj_len)
        {
          if (!ec)
          {
            printf("write %td\n",tj_len);
            do_read();
          }
        });
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
  std::string data = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
};

void do_accept(tcp::acceptor& acc,asio::io_service &iosvr)
  {
    acc.async_accept([&iosvr,&acc](std::error_code ec,tcp::socket socket_)
        {
          if (!ec)
          {
            //std::make_shared<session>(std::move(socket_))->start();
            std::shared_ptr<session> okpt( new session(std::move(socket_)) );
            okpt->start();
            printf("Session %p has be Constr.. socket:%p\n",okpt.get(),&socket_);

          }

          do_accept(acc,iosvr);
        });
  }

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Usage: async_tcp_echo_server <port>\n";
      return 1;
    }
  printf("Main threadId:%td\n",syscall(SYS_gettid));
  int port = atoi(argv[1]);

  asio::io_service accetp_iosvr_;
  asio::io_service work_iosvr_;

  tcp::endpoint ep_(tcp::v4(), port);
  //tcp::acceptor accept_(accetp_iosvr_,tcp::endpoint(tcp::v4(), port));
  tcp::acceptor accept_(accetp_iosvr_);
  accept_.open(ep_.protocol());
	accept_.set_option(tcp::acceptor::reuse_address(true));
	accept_.bind(ep_);
	accept_.listen();

  do_accept(accept_,accetp_iosvr_);

  std::thread([&accetp_iosvr_](){
    accetp_iosvr_.run();
  }).detach();
     //server s(std::atoi(argv[1]));
    // s.initServer();
    // for(int i = 0 ; i < 4 ;i++)
    //   std::thread( [&io_service](){io_service.run();} ).detach();

    poll(NULL,0,-1);
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
