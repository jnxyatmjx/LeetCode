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
    //printf("Session %p has be Delete.. socket:%p\n",this,&socket_);
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
        [this,self](std::error_code ec, std::size_t length)
        {
          if (!ec)
          {
            //printf("read %s len:%td\n",data_,length);
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
            //printf("write %td\n",tj_len);
            do_read();
          }
        });
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
  std::string data = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
};

void do_accept(tcp::acceptor& acc,asio::io_context &ioAcceptSvr,asio::io_context &ioWorkSvr)
  {
    std::shared_ptr<tcp::socket> sock_newgo_( new tcp::socket(ioWorkSvr) );
    acc.async_accept(*sock_newgo_,[&acc,&ioAcceptSvr,&ioWorkSvr, sock_newgo_ ](std::error_code ec){
        if (!ec)
          {
            std::shared_ptr<session> okpt( new session(std::move(*sock_newgo_)) );
            okpt->start();
            printf("sock_newgo_ 111 count:%td\n",sock_newgo_.use_count());
          }

          do_accept(acc,ioAcceptSvr,ioWorkSvr);
    });
    printf("sock_newgo_ 222 count:%td\n",sock_newgo_.use_count());

#if 0
    acc.async_accept([&acc,&ioAcceptSvr,&ioWorkSvr](std::error_code ec,tcp::socket socket_)
        {
          if (!ec)
          {
            //std::make_shared<session>(std::move(socket_))->start();
            //上句 与 以下两句 作用相同

            // 创建类 sessoin智能指针对象
            std::shared_ptr<session> okpt( new session(std::move(socket_)) );
            okpt->start();// 通过shared_from_this() 创建类 session 智能指针对象

            
          }

          do_accept(acc,ioAcceptSvr,ioWorkSvr);
        });
#endif
  }

class A : public std::enable_shared_from_this<A>
{
public:
  A(){printf("Construct A\n");}
  ~A(){printf("Destruct A \n");}

/*
  WHY --> do_read  share count:2

*/
  void startA()
  {
    auto self(shared_from_this());
      printf("class A cout:%td\n",self.use_count()); //class A cout:2
  }
};

int main(int argc, char* argv[])
{

  {
    // std::shared_ptr<A> a(new A()); //创建 A对象智能指针
    // a->startA();                   //调用 shared_from_this() 又创建A对象智能指针
    
    /*
        |||
        |||
    */ 
    std::make_shared<A>()->startA();

    //所以 class A cout:2
  }

  int port = -1;
  try
  {
    if (argc < 2)
    {
      std::cerr << "Usage: async_tcp_echo_server <port> 8970\n";
      port = 8970;
    }else
    {
      port = atoi(argv[1]);
    }
  printf("Main threadId:%td\n",syscall(SYS_gettid));

  asio::io_context accetp_iosvr_;
  asio::io_context work_iosvr_;


  tcp::endpoint ep_(tcp::v4(), port);
  //tcp::acceptor accept_(accetp_iosvr_,tcp::endpoint(tcp::v4(), port));
  tcp::acceptor accept_(accetp_iosvr_);
  accept_.open(ep_.protocol());
	accept_.set_option(tcp::acceptor::reuse_address(true));
	accept_.bind(ep_);
	accept_.listen();

  //create I/O context. Use io_context::work to Keep I/0 context Alive
  auto iowork_ = std::make_shared<asio::io_context::work>(work_iosvr_); 

  //create Accept context.
  do_accept(accept_,accetp_iosvr_,work_iosvr_);


  //create I/O thread. Use io_context::work to Keep I/0 context Alive
  //auto iowork_ = std::make_shared<asio::io_context::work>(work_iosvr_); 
  std::thread([&work_iosvr_](){
    work_iosvr_.run();
  }).detach();


  //create Accept thread
  std::thread([&accetp_iosvr_](){
    accetp_iosvr_.run();
  }).detach();

     //server s(std::atoi(argv[1]));
    // s.initServer();
    // for(int i = 0 ; i < 4 ;i++)
    //   std::thread( [&io_context](){io_context.run();} ).detach();

    poll(NULL,0,-1);
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
