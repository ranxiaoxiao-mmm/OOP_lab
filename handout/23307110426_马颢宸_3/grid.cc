#include "grid.h"

#include <array>
#include <cctype>
#include <iostream>

static size_t maxGridLine(Grid const &grid) {
    size_t ret{0};
    for (auto const &line : grid) ret = std::max(ret, line.size());
    return ret + 2;
}

inline bool isSymbol(char c) {
    return (c != '.' && !isdigit(c));
}

bool isSymbolAdjacent(char c, size_t i, size_t j, Grid const &grid) {
    std::array<std::pair<int, int>, 8> positions{
        {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
    for (const auto [delta_i, delta_j] : positions) {
        auto c = grid[i + delta_i][j + delta_j];
        if (isSymbol(c)) { return true; }
    }

    return false;
}

Grid readGrid(std::istream &in) {
    Grid grid;
    std::string line;
    while (std::getline(in, line)) {
        if (line.size() == 0) break;
        grid.push_back(line);
    }
    return grid;
}

Grid frameGrid(Grid const &grid, char SEP) {
    Grid framed;
    auto max = maxGridLine(grid);

    framed.push_back(std::string(max, SEP));
    for (auto const &line : grid) {
        std::string new_line = '.' + line + std::string(max - 2 - line.size(), ' ') + '.';
        framed.push_back(new_line);
    }
    framed.push_back(std::string(max, SEP));

    return framed;
}

// todo: implement two functions:
// void print(std::ostream &out, Grid const &);
// std::vector<unsigned> findEffectiveNumber(Grid const &);

void print(std::ostream &out, Grid const &grid) {
    for (auto const &line : grid) out << line << '\n';
}

std::vector<unsigned> findEffectiveNumber(Grid const &grid) {
    std::vector<unsigned> numbers;
    for (size_t i = 1; i < grid.size() - 1; ++i) {
        for (size_t j = 1; j < grid[i].size() - 1; ++j) {
            std::vector<unsigned> number;
            bool is_effect = false;
            while(isdigit(grid[i][j])) {
                number.push_back(grid[i][j] - '0');
                if(isSymbolAdjacent(grid[i][j], i, j, grid)){
                    is_effect = true;
                }
                ++j;
            }
            if (is_effect) {
                unsigned effect_num{0};
                for(auto n : number) {
                    effect_num = effect_num * 10 + n;
                }
                numbers.push_back(effect_num);
            }
        }
    }
    return numbers;
}