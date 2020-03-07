#include "Database.h"

void Database::onDataRecieved(unsigned char data)
{
    auto lock = std::lock_guard(_mutex);
    _data.emplace_back(data);
}

size_t Database::size()
{
    auto lock = std::lock_guard(_mutex);
    return _data.size();
}
