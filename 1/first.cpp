//
// Created by kyomawolf on 01.12.23.
//
#include <string>
#include <fstream>
#include <iostream>


int getNumberFromLeft(std::string line) {
    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            return line[i] - '0';
        }
    }
    return 0;
}

int getNumberFromRight(std::string line) {
    for (int i = line.length() - 1; i >= 0; i--) {
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