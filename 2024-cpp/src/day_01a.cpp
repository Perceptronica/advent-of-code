#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
  std::string input = "../sample_tests/day_01.in";
  if (argc > 1) {
    input = argv[1];
  }

  std::vector<uint32_t> a;
  std::vector<uint32_t> b;
  uint32_t answer{0};

  std::ifstream file(input);
  uint32_t val1, val2;
  while (file >> val1 >> val2) {
    a.push_back(val1);
    b.push_back(val2);
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  for (size_t i = 0; i < a.size(); ++i) {
    answer += abs(a[i] - b[i]);
  }
  std::cout << answer << std::endl;
}