#pragma once

#include <list>
#include <mutex>

class Database
{
public:
    void onDataRecieved(unsigned char);

    size_t size();

private:
    using Data = std::list<unsigned char>;

    std::mutex _mutex;
    Data _data;
};
