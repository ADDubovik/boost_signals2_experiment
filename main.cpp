#include <iostream>
#include <thread>
#include <chrono>

#include "Manager.h"

int main()
{
    Manager manager;
    manager.run();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}
