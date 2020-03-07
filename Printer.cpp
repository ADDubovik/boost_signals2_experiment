#include "Printer.h"

#include <iostream>
#include <iomanip>
#include <exception>

Printer::Printer() = default;

Printer::~Printer()
{
    stop();
}

void Printer::onDataRecieved(unsigned char data)
{
    auto lock = std::lock_guard(_mutex);
    if (_isRunning) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data);
    } else {
        throw std::runtime_error("Printer::onDataReceived was invoked in stopped state");
    }
}

void Printer::run()
{
    auto lock = std::lock_guard(_mutex);
    _isRunning = true;
}

void Printer::stop()
{
    auto lock = std::lock_guard(_mutex);
    _isRunning = false;
}
