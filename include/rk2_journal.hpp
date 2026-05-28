#pragma once

#include <iosfwd>
#include <string>
#include <vector>

namespace rk2 {

class Journal {
public:
    explicit Journal(std::string title);
    void addEntry(const std::string& entry);
    const std::string& getTitle() const noexcept;
    const std::vector<std::string>& getEntries() const noexcept;

private:
    std::string title_;
    std::vector<std::string> entries_;
    std::size_t count_{};
};

struct SavingManager {
    static void save(const Journal& journal, std::ostream& output);
};

} // namespace rk2
