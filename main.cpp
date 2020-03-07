#include <iostream>
#include <thread>
#include <chrono>

#include "Manager.h"

int main()
{
    Manager manager;
    manager.run();

    for (auto i = 0; i < 100; ++i) {
        manager.rotatePrinters();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
