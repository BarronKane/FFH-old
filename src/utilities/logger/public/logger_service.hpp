#pragma once

#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

namespace utilities
{

class logger_service
    : public boost::asio::execution_context::service
{

public:

    typedef logger_service key_type;

    struct logger_impl
    {
        explicit logger_impl(const std::string &ident) : identifier(ident) {}
        std::string identifier;
    };

    typedef logger_impl *impl_type;

    // Creates a thread to run a private io_context.
    logger_service(boost::asio::execution_context &context)
        : boost::asio::execution_context::service(context),
          work_io_context_(),
          work_(boost::asio::make_work_guard(work_io_context_)),
          work_thread_(new boost::thread(
              boost::bind(&boost::asio::io_context::run, &work_io_context_)))
    {
    }

    // Destructor shuts down the private io_context.
    ~logger_service()
    {
        // Indicate that we have finished with the private io_context. Its
        // io_context::run() function will exit once all other work has completed.
        work_.reset();
        if (work_thread_)
            work_thread_->join();
    }

    // Destroy all user-defined handler objects owned by the service.
    void shutdown()
    {
    }

    // Return a null logger implementation.
    impl_type null() const
    {
        return 0;
    }

    // Create a new logger implementation.
    void create(impl_type &impl, const std::string &identifier)
    {
        impl = new logger_impl(identifier);
    }

    // Destroy a logger implementation.
    void destroy(impl_type &impl)
    {
        delete impl;
        impl = null();
    }

    // Set the output file for the logger. The current implementation sets the
    // output file for all logger instances, and so the impl parameter is not
    // actually needed. It is retained here to illustrate how service functions
    // are typically defined.
    void use_file(impl_type & /*impl*/, const std::string &file)
    {
        // Pass the work of opening the file to the background thread.
        boost::asio::post(work_io_context_, boost::bind(
                                                &logger_service::use_file_impl, this, file));
    }

    void log(impl_type &impl, const std::string &message)
    {
        // Format text.
        std::ostringstream os;
        std::ostringstream oo;

        os << boost::posix_time::second_clock::local_time()
           << " <" << impl->identifier << ">" << ": " 
           << message;

        oo << " <" << impl->identifier << ">" << ": "
           << message;

        // Pass io work to the background thread.
        boost::asio::post(work_io_context_, boost::bind(
            &logger_service::log_impl, this, os.str()));

        boost::asio::post(work_io_context_, boost::bind(
            &logger_service::log_console_impl, this, oo.str()));

    }

private:

    // Open the output file from within the private thread.
    void use_file_impl(const std::string &file)
    {
        ofstream_.close();
        ofstream_.clear();
        ofstream_.open(file.c_str());
    }

    // TODO: Log levels.
    // Log a message from within the private thread.
    void log_impl(const std::string &text)
    {
        ofstream_ << text << std::endl;
    }

    // Mirror message to console.
    void log_console_impl(const std::string& text)
    {
        std::cout << text << std::endl;
    }

    // Private io_context used for performing logging operations.
    boost::asio::io_context work_io_context_;

    // Work for the private io_context to perform. If we do not give the
    // io_context some work to do then the io_context::run() function will exit
    // immediately.
    boost::asio::executor_work_guard<
        boost::asio::io_context::executor_type>
        work_;

    // Thread used for running the work io_context's run loop.
    boost::scoped_ptr<boost::thread> work_thread_;

    // The file to which log messages will be written.
    std::ofstream ofstream_;
};

} // namespace utilities
