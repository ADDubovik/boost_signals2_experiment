#include <chrono>

#include "Source.h"

Source::Source() = default;

Source::~Source()
{
    _semaphore = false;

    if (_thread.joinable()) {
        _thread.join();
    }
}

void Source::run()
{
    _semaphore = true;

    _thread = std::thread([this](){
        while (_semaphore) {
            signal(static_cast<unsigned char>(rand() & 0xff));
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    });
}
