#include <bits/stdc++.h>

int32_t f(std::string &line) {
  int acc{0};
  std::smatch match;
  std::regex reg(R"(mul\((\d+)+,(\d+)+\))");
  while (std::regex_search(line, match, reg)) {
    int a = std::stoi(match[1].str());
    int b = std::stoi(match[2].str());
    acc += a * b;
    line = match.suffix().str();
  }
  return acc;
}

int main(int argc, char *argv[]) {
  std::string input = "../sample_tests/day_03.input";
  if (argc > 1) {
    input = argv[1];
  }

  std::fstream file(input);
  std::string line;
  int32_t answer{0};
  while (std::getline(file, line)) {
    answer += f(line);
  }
  std::cout << answer << std::endl;
}
