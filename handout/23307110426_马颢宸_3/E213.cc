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
    double avg;
};

using Students = std::vector<Student>;

Students readStudents(std::istream &);
Students generateStudents(std::istream &);

void readScore(std::istream &, std::vector<unsigned> &scores);
void generateScore(std::vector<unsigned> &scores);

double average(std::vector<unsigned> const &scores);

unsigned randInt(unsigned start, unsigned stop);
void print(std::ostream &, Students const &);

int main() {
    auto students = readStudents(std::cin);
    std::sort(students.begin(), students.end(),
              [](Student const &a, Student const &b) { return !(a.avg < b.avg); });

    print(std::cout, students);

    return 0;
}

// todo: implement all functions

Students readStudents(std::istream &in) {
    Students students;
    students.reserve(MAX_NAMES);
    std::string name;
    while (in >> name) {
        Student student;
        student.name = name;
        readScore(in,student.scores);
        student.avg = average(student.scores);
        students.emplace_back(student);
        if (students.size() == MAX_NAMES) break;
    }

    return students;
}

void readScore(std::istream &in, std::vector<unsigned> &scores){
    scores.reserve(8);
    unsigned score;
    for (int i = 0; i < 8; ++i) {
        std::cin >> score;
        scores.push_back(score);
    }
}

double average(std::vector<unsigned> const &scores) {
    std::vector<unsigned> temp = scores;
    std::sort(temp.begin()+2, temp.end());
    double avg = temp[0]*0.4 + temp[1]*0.4 + ((temp[4] + temp[5])*0.5)*0.2;
    avg = static_cast<int>(avg * 10) / 10.0;
    return avg;
}

void print(std::ostream &cout, Students const &students) {
    for (const auto &student : students) {
        std::cout << std::format("{} ", student.name);
        std::cout << student.avg << ' ';
        for (const auto &score : student.scores) { std::cout << score << ' '; }
        std::cout << '\n';
    }
}