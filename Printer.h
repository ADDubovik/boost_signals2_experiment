#pragma once

#include <mutex>

class Printer
{
public:
    Printer();
    ~Printer();

    void onDataRecieved(unsigned char);

    void run();
    void stop();

private:
    std::mutex _mutex;
    bool _isRunning = false;
};
