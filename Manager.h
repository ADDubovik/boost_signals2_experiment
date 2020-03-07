#pragma once

#include <memory>
#include <list>

#include "Source.h"
#include "Database.h"
#include "Printer.h"

class Manager
{
public:
    Manager();
    ~Manager();

    void run();

    void rotatePrinters();

private:
    using Connection = boost::signals2::scoped_connection;
    using PrinterWithConnection = std::pair<Printer, std::optional<Connection>>;

    Database _database;
    Printer _printer;
    std::list<PrinterWithConnection> _printers;
    Source _source;
};
