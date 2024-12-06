#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  std::string input = "../sample_tests/day_01.input";
  if (argc > 1) {
    input = argv[1];
  }

  std::vector<uint32_t> a;
  std::vector<uint32_t> b;
  uint32_t answer{0};
  std::map<uint32_t, uint32_t> stats;

  std::ifstream file(input);
  uint32_t val1, val2;
  while (file >> val1 >> val2) {
    a.push_back(val1);
    b.push_back(val2);
    ++stats[val2];
  }

  for (const auto &elem : a) {
    answer += (elem * stats[elem]);
  }
  std::cout << answer << std::endl;
}
