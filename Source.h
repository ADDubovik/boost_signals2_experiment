#pragma once

#include <boost/signals2.hpp>

#include <thread>

// RAII
class Source
{
public:
    Source();
    ~Source();

    mutable boost::signals2::signal<void(unsigned char)> signal;

    void run();

private:
    using Semaphore = std::atomic<bool>;

    Semaphore _semaphore = false;
    std::thread _thread;
};
