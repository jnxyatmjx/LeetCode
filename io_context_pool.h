//
// io_context_pool.hpp
// ~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_SERVER2_IO_SERVICE_POOL_HPP
#define HTTP_SERVER2_IO_SERVICE_POOL_HPP

#include "asio.hpp"

#include <list>
#include <vector>
#include <vector>
#include <memory>

/// A pool of io_context objects.
class io_context_pool
{
public:
  /// Construct the io_context pool.
  explicit io_context_pool(std::size_t pool_size);

  /// Run all io_context objects in the pool.
  void run();

  /// Stop all io_context objects in the pool.
  void stop();

  /// Get an io_context to use.
  asio::io_context& get_io_context();

private:
  typedef std::shared_ptr<asio::io_context> io_context_ptr;

  /// The pool of io_contexts.
  std::vector<io_context_ptr> io_contexts_;

  /// The work-tracking executors that keep the io_contexts running.
  std::list<asio::any_io_executor> work_;

  /// The next io_context to use for a connection.
  std::size_t next_io_context_;
  
};

#endif // HTTP_SERVER2_IO_SERVICE_POOL_HPP
