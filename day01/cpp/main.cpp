#include <fstream>
#include <iostream>
#include <string>
#include <strings.h>
#include <vector>

void read_test(void) {
  // std::ifstream file("../test.txt");
  std::ifstream file("../input.txt");

  if (!file) {
    std::cerr << "Cannot find the file." << std::endl;
  }

  std::string line;

  int sum = 0;
  while (std::getline(file, line)) {
    // std::cout << line << std::endl;
    std::string number = "";
    for (auto &a : line) {
      if (isdigit(a)) {
        number += a;
      }
    }
    std::string final_number = "";
    final_number += number.front();
    final_number += number.back();
    // std::cout << final_number << std::endl;
    sum += std::stoi(final_number);
  }
  std::cout << sum << std::endl;
}

void read_input(void) {
  std::ifstream file("../test.txt");

  if (!file) {
    std::cerr << "Cannot find the file." << std::endl;
  }

  std::string line;

  while (std::getline(file, line)) {
    std::cout << line << std::endl;
    for (auto &a : line) {
      std::cout << a << std::endl;
    }
  }
}

void substring(void) {

  // std::ifstream file("../test2.txt");
  std::ifstream file("../input.txt");

  if (!file) {
    std::cerr << "Cannot find the file." << std::endl;
  }

  std::vector<std::string> strings = {
      "zero", "one", "two",   "three", "four",
      "five", "six", "seven", "eight", "nine",
  };

  std::string line;

  int sum = 0;

  while (std::getline(file, line)) {
    int min_pos = 10000;
    int max_pos = -1;
    int min_num = 0;
    int max_num = 0;
    for (size_t i = 0; i < strings.size(); i++) {
      int pos = 0;
      while (1) {
        pos = line.find(strings.at(i), pos);
        if (pos == std::string::npos) {
          break;
        }
        if (pos < min_pos) {
          min_pos = pos;
          min_num = i;
        }

        if (pos > max_pos) {
          max_pos = pos;
          max_num = i;
        }
        pos++;
      }
    }
    std::cout << "min_pos = " << min_pos << " num " << min_num << std::endl;
    std::cout << "max_pos = " << max_pos << " num " << max_num << std::endl;

    int index = 0;
    for (auto &a : line) {
      if (isdigit(a)) {
        if (index < min_pos) {
          min_pos = index;
          min_num = a - '0';
          std::cout << "index = " << index << " min num " << min_num
                    << std::endl;
          // min_num = std::atoi(&a);
        }
        if (index > max_pos) {
          max_pos = index;
          max_num = a - '0';
          std::cout << "index = " << index << " max num " << max_num
                    << std::endl;
          // max_num = std::atoi(&a);
        }
      }
      index++;
    }
    const int add = (min_num * 10) + max_num;
    std::cout << line << "\t = " << add << std::endl;

    sum += add;
  }
  std::cout << sum << std::endl;
}

int main() { substring(); }
