#include "rk2_journal.hpp"

#include <ostream>
#include <utility>

namespace rk2 {

Journal::Journal(std::string title)
    : title_(std::move(title))
{
}

void Journal::addEntry(const std::string& entry)
{
    ++count_;
    entries_.push_back(std::to_string(count_) + ": " + entry);
}

const std::string& Journal::getTitle() const noexcept
{
    return title_;
}

const std::vector<std::string>& Journal::getEntries() const noexcept
{
    return entries_;
}

void SavingManager::save(const Journal& journal, std::ostream& output)
{
    output << journal.getTitle() << '\n';
    for (const auto& entry : journal.getEntries()) {
        output << entry << '\n';
    }
}

} // namespace rk2
