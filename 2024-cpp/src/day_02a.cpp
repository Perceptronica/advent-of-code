#include <bits/stdc++.h>
#include <fstream>

struct flags {
  bool is_safe;
  bool big_diff; // when the diff > 3
  bool asc_order;
  bool desc_order;

  void update(int d) {
    big_diff = (abs(d) > 3 || d == 0) ? true : false;
    asc_order = (d > 0) ? true : asc_order;
    desc_order = (d < 0) ? true : desc_order;
    is_safe = (!big_diff) && (asc_order != desc_order);
  }

  bool safe() { return is_safe; }

  flags()
      : is_safe(true), big_diff(false), asc_order(false), desc_order(false) {}
};

uint32_t f(std::vector<uint32_t> &v) {
  struct flags f;
  size_t v_sz = v.size();

  for (size_t i = 1; i < v_sz; ++i) {
    int diff = v[i] - v[i - 1];
    f.update(diff);
    if (!f.safe()) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  std::string input = "../sample_tests/day_02.input";
  if (argc > 1) {
    input = static_cast<std::string>(argv[1]);
  }

  std::vector<uint32_t> v;
  uint32_t answer{0};

  std::string line;
  std::fstream file(input);
  while (std::getline(file, line)) {
    v.clear();
    std::stringstream s(line);

    uint32_t num;
    while (s >> num) {
      v.push_back(num);
    }
    answer += f(v);
  }

  std::cout << answer << std::endl;
}
