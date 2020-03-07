#include "Manager.h"

Manager::Manager()
{
    _source.signal.connect([this](unsigned char data){ _database.onDataRecieved(data); });
    _source.signal.connect([this](unsigned char data){ _printer.onDataRecieved(data); });
}

Manager::~Manager() = default;

void Manager::run()
{
    _printer.run();
    _source.run();
}
