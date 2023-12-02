#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <strings.h>
#include <vector>

int getGameNumber(std::string &s) {
  auto pos = s.find(':');
  std::string game = s.substr(0, pos);
  std::istringstream ss(game);
  std::string number;
  ss >> number;
  ss >> number;
  return std::stoi(number);
}

void removeGame(std::string &s) {
  auto pos = s.find(':');
  s.erase(0, pos + 2);
}

bool isColorOkay(int number, std::string color) {
  if ((color.compare("red") != 0) && (color.compare("green") != 0) &&
      (color.compare("blue") != 0)) {
    std::cout << color << " FUCK" << std::endl;
    return false;
  }

  if ((color.compare("red") == 0) && number <= 12) {
    return true;
  }
  if ((color.compare("green") == 0) && number <= 13) {
    return true;
  }
  if ((color.compare("blue") == 0) && number <= 14) {
    return true;
  }
  return false;
}

void part_one(void) {

  // std::ifstream file("../test.txt");
  std::ifstream file("../input.txt");

  if (!file) {
    std::cerr << "Cannot find the file." << std::endl;
  }

  std::string line;
  int sum = 0;
  while (std::getline(file, line)) {
    std::cout << std::endl;
    std::cout << line << std::endl;
    // find game number
    int game_num = getGameNumber(line);
    std::cout << game_num << std::endl;
    removeGame(line);

    // count the colors
    auto pos = 0;
    std::string token;
    bool line_good = true;
    while ((pos = line.find(';')) != std::string::npos) {
      token = line.substr(0, pos);
      // std::cout << token << std::endl;
      // print individual colors
      auto sub_pos = 0;
      std::string color;
      while ((sub_pos = token.find(',')) != std::string::npos) {
        color = token.substr(0, sub_pos);
        std::cout << color << std::endl;
        std::istringstream num_color(color);
        std::string num;
        std::string col;
        num_color >> num;
        num_color >> col;
        if (!isColorOkay(std::stoi(num), col)) {
          line_good = false;
        }
        token.erase(0, sub_pos + 2);
      }
      std::cout << token << std::endl;
      std::istringstream num_color(token);
      std::string num;
      std::string col;
      num_color >> num;
      num_color >> col;
      if (!isColorOkay(std::stoi(num), col)) {
        line_good = false;
      }
      line.erase(0, pos + 2);
    }
    // std::cout << line << std::endl;
    auto sub_pos = 0;
    std::string color;
    while ((sub_pos = line.find(',')) != std::string::npos) {
      color = line.substr(0, sub_pos);
      std::cout << color << std::endl;
      std::istringstream num_color(color);
      std::string num;
      std::string col;
      num_color >> num;
      num_color >> col;
      if (!isColorOkay(std::stoi(num), col)) {
        line_good = false;
      }
      line.erase(0, sub_pos + 2);
    }
    std::cout << line << std::endl;
    std::istringstream num_color(line);
    std::string num;
    std::string col;
    num_color >> num;
    num_color >> col;
    if (!isColorOkay(std::stoi(num), col)) {
      line_good = false;
    }
    if (line_good) {
      std::cout << "good" << std::endl;
      sum += game_num;
    } else {
      std::cout << "bad" << std::endl;
    }
  }
  std::cout << sum << std::endl;
}

void findMax(int *r, int *g, int *b, const int num, std::string color) {
  if (color.compare("red") == 0) {
    if (*r < num) {
      *r = num;
    }
    return;
  }

  if (color.compare("green") == 0) {
    if (*g < num) {
      *g = num;
    }
    return;
  }

  if (color.compare("blue") == 0) {
    if (*b < num) {
      *b = num;
    }
    return;
  }
}

void part_two(void) {
  // std::ifstream file("../test.txt");
  std::ifstream file("../input.txt");

  if (!file) {
    std::cerr << "Cannot find the file." << std::endl;
  }

  std::string line;
  int sum = 0;
  while (std::getline(file, line)) {
    std::cout << std::endl;
    std::cout << line << std::endl;
    // find game number
    int game_num = getGameNumber(line);
    std::cout << game_num << std::endl;
    removeGame(line);

    // count the colors
    auto pos = 0;
    std::string token;
    bool line_good = true;
    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;
    while ((pos = line.find(';')) != std::string::npos) {
      token = line.substr(0, pos);
      // std::cout << token << std::endl;
      // print individual colors
      auto sub_pos = 0;
      std::string color;
      while ((sub_pos = token.find(',')) != std::string::npos) {
        color = token.substr(0, sub_pos);
        std::cout << color << std::endl;
        std::istringstream num_color(color);
        std::string num;
        std::string col;
        num_color >> num;
        num_color >> col;
        findMax(&max_red, &max_green, &max_blue, std::stoi(num), col);
        token.erase(0, sub_pos + 2);
      }
      std::cout << token << std::endl;
      std::istringstream num_color(token);
      std::string num;
      std::string col;
      num_color >> num;
      num_color >> col;
      findMax(&max_red, &max_green, &max_blue, std::stoi(num), col);
      line.erase(0, pos + 2);
    }
    // std::cout << line << std::endl;
    auto sub_pos = 0;
    std::string color;
    while ((sub_pos = line.find(',')) != std::string::npos) {
      color = line.substr(0, sub_pos);
      std::cout << color << std::endl;
      std::istringstream num_color(color);
      std::string num;
      std::string col;
      num_color >> num;
      num_color >> col;
      findMax(&max_red, &max_green, &max_blue, std::stoi(num), col);
      line.erase(0, sub_pos + 2);
    }
    std::cout << line << std::endl;
    std::istringstream num_color(line);
    std::string num;
    std::string col;
    num_color >> num;
    num_color >> col;
    findMax(&max_red, &max_green, &max_blue, std::stoi(num), col);
    sum += max_red * max_green * max_blue;
  }
  std::cout << sum << std::endl;
}

int main() { part_two(); }
