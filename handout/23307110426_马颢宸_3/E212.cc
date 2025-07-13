#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

static int const MAX_NAMES = 20000;
struct Student {
    std::string name;
    std::vector<unsigned> scores;
};

using Students = std::vector<Student>;

Students generateStudents(std::istream &);
void generateScore(std::vector<unsigned> &scores);

unsigned randInt(unsigned start, unsigned stop);
void print(std::ostream &, Students const &);

int main() {
    auto students = generateStudents(std::cin);
    std::sort(students.begin(), students.end(),
              [](Student const &a, Student const &b) { return a.name < b.name; });

    print(std::cout, students);

    return 0;
}

// todo: implement all functions
Students generateStudents(std::istream &in) {
    Students students;
    students.reserve(MAX_NAMES);
    std::string name;
    while (in >> name) {
        Student student{name, {}};
        generateScore(student.scores);
        students.emplace_back(student);
        if (students.size() == MAX_NAMES) break;
    }

    return students;
}

void generateScore(std::vector<unsigned> &scores) {
    scores.reserve(8);
    scores.push_back(randInt(60,90));
    scores.push_back(randInt(50,85));
    for(auto &score : std::vector<int>(6)) { 
        score = randInt(70,95);
        scores.push_back(score); 
    }
}

unsigned randInt(unsigned start, unsigned stop) {
    static std::default_random_engine random(std::random_device{}());
    std::uniform_int_distribution<int> dis(start, stop);
    unsigned num = dis(random);
    return num;
}

void print(std::ostream &cout, Students const &students) {
    for (const auto &student : students) {
        std::cout << std::format("{} ", student.name);
        for (const auto &score : student.scores) { std::cout << score << ' '; }
        std::cout << '\n';
    }
}