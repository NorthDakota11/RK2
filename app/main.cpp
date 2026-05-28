#include "rk2_journal.hpp"

#include <iostream>

int main()
{
    rk2::Journal journal{"SRP demo"};
    journal.addEntry("Journal stores entries");
    journal.addEntry("SavingManager writes entries to a stream");

    rk2::SavingManager::save(journal, std::cout);
    return 0;
}
