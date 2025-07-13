#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

static int const MAX_NAMES = 20000;
using Names = std::vector<std::string>;

Names generate(std::istream &);
Names generate_2(Names const &names);
void print(std::ostream &, Names const &);

int main() {
    auto names = generate(std::cin);
    sort(names.begin(), names.end());
    auto names2 = generate_2(names);
    print(std::cout, names2);

    return 0;
}

Names generate(std::istream &in) {
    Names names;
    names.reserve(MAX_NAMES);
    std::string name;
    while (in >> name) {
        if (name.size() < 10 || name.size() > 12) continue;
        names.emplace_back(name);
        // if (names.size() == MAX_NAMES) break;
    }

    return names;
}

Names generate_2(Names const &names) {
    Names names2;
    names2.reserve(MAX_NAMES);
    for (const auto &name : names) {
        names2.emplace_back(name);
        if (names2.size() == MAX_NAMES) break;
    }
    return names2;
}

void print(std::ostream &out, Names const &names) {
    for (const auto &name : names) { out << name << '\n'; }
}
