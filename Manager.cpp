#include "Manager.h"

namespace {
const size_t printersCount = 16;
} // namespace

Manager::Manager()
{
    _source.signal.connect([this](unsigned char data){ _database.onDataRecieved(data); });

    for (size_t i = 0u; i < printersCount; ++i) {
        _printers.emplace_back();
    }
}

Manager::~Manager() = default;

void Manager::run()
{
    _source.run();
}

void Manager::rotatePrinters()
{
    for (auto &elem : _printers) {
        if (rand() & 1) {
            // switching connection state
            if (elem.second) {
                elem.second.reset();
                elem.first.stop();
            } else {
                elem.first.run();
                elem.second = _source.signal.connect([&](unsigned char data){ elem.first.onDataRecieved(data); });
            }
        }
    }
}
