//
// Created by kyomawolf on 01.12.23.
//
//
// Created by kyomawolf on 01.12.23.
//
#include <string>
#include <fstream>
#include <iostream>

std::string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

std::pair<int, size_t> isNumberSpelled (const std::string& line) {
    auto ret = std::make_pair(0, std::string::npos);
    for (auto j = 0; j < 9; j++) {
        if (line.find(numbers[j]) < ret.second) {
            ret = {j + 1, line.find(numbers[j])};
        }
    }

    return ret;
}


std::pair<int, size_t> isNumberSpelledBackwards (const std::string& line) {
    auto ret = std::make_pair(0, 0);
    for (auto j = 0; j < 9; j++) {
        auto tmp = line.rfind(numbers[j]);
        if (tmp != std::string::npos && tmp > ret.second) {
            ret = {j + 1, tmp};
        }
    }
    return ret;
}

int getNumberFromLeft(std::string line) {
    auto ret = isNumberSpelled(line);
    if (ret.first != 0) {
        auto sub = line.substr(0, ret.second);
        for (auto i = 0; i < sub.length(); i++) {
            if (sub[i] >= '0' && sub[i] <= '9') {
                return sub[i] - '0';
            }
        }
        return ret.first;
    }
    for (auto i = 0; i < line.length(); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            return line[i] - '0';
        }
    }
    return 0;
}

int getNumberFromRight(std::string line) {
    auto ret = isNumberSpelledBackwards(line);
    if (ret.first != 0) {
        auto sub = line.substr(ret.second);
        for (long i = sub.length() - 1; i >= 0; i--) {
            if (sub[i] >= '0' && sub[i] <= '9') {
                return sub[i] - '0';
            }
        }
        return ret.first;
    }
    for (long i = line.length() - 1; i >= 0; i--) {
        if (line[i] >= '0' && line[i] <= '9') {
            return line[i] - '0';
        }
    }
    return 0;
}

int main() {
    std::ifstream ifs("input.txt");
    int finalnum = 0;
    for (std::string line; std::getline(ifs, line);) {
        std::string local = line;
        int num = getNumberFromLeft(local);
        num *= 10;
        num += getNumberFromRight(local);
        finalnum += num;
    }
    std::cout << finalnum << std::endl;
}