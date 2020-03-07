#pragma once

#include "Source.h"
#include "Database.h"
#include "Printer.h"

class Manager
{
public:
    Manager();
    ~Manager();

    void run();

private:
    Source _source;
    Database _database;
    Printer _printer;
};
