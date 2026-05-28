#include "rk2_journal.hpp"

#include <cassert>
#include <sstream>
#include <string>

int main()
{
    rk2::Journal journal{"Test journal"};
    journal.addEntry("first note");
    journal.addEntry("second note");

    assert(journal.getTitle() == "Test journal");
    assert(journal.getEntries().size() == 2);
    assert(journal.getEntries()[0] == "1: first note");
    assert(journal.getEntries()[1] == "2: second note");

    std::ostringstream output;
    rk2::SavingManager::save(journal, output);

    const std::string expected = "Test journal\n1: first note\n2: second note\n";
    assert(output.str() == expected);

    return 0;
}
