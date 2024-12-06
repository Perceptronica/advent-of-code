#include <bits/stdc++.h>
#include <cstdint>

std::vector<std::string> map;
std::set<std::pair<int32_t, int32_t>> visited;

std::pair<int32_t, int32_t> d_pos(std::pair<int32_t, int32_t> &prev_d_pos) {
  int32_t p1 = prev_d_pos.first;
  int32_t p2 = prev_d_pos.second;
  if (p1 == -1 && p2 == 0) {
    return std::make_pair(0, 1);
  } else if (p1 == 0 && p2 == 1) {
    return std::make_pair(1, 0);
  } else if (p1 == 1 && p2 == 0) {
    return std::make_pair(0, -1);
  } else if (p1 == 0 && p2 == -1) {
    return std::make_pair(-1, 0);
  }
  return std::make_pair(0, 0);
}

int32_t solve() {
  int acc{0};
  int32_t x = 0, y = 0, dx, dy;
  std::pair<int32_t, int32_t> curr_d_pos = {-1, 0};

  for (std::size_t i = 0; i < map.size(); ++i) {
    for (std::size_t j = 0; j < map[i].length(); ++j) {
      if (map[i][j] == '^') {
        x = static_cast<int32_t>(i);
        y = static_cast<int32_t>(j);
        break;
      }
    }
  }
  while (y < map[0].length() && y >= 0 && x >= 0 && x < map.size()) {

    visited.insert(std::make_pair(x, y));
    dx = curr_d_pos.first;
    dy = curr_d_pos.second;
    if (y + dy >= map[0].length() || y + dy < 0 || x + dx >= map.size() ||
        x + dx < 0) {
      break;
    } else if (map[x + dx][y + dy] == '#') {
      curr_d_pos = d_pos(curr_d_pos);
    }
    x += curr_d_pos.first;
    y += curr_d_pos.second;
  }

  std::cout << x << ' ' << y << std::endl;
  acc = visited.size();
  return acc;
}

int main(int argc, char *argv[]) {
  std::string input = "../sample_tests/day_06.input";
  if (argc > 1) {
    input = argv[1];
  }

  std::fstream file(input);
  std::string line;
  while (std::getline(file, line)) {
    map.push_back(line);
  }

  int32_t answer{solve()};
  std::cout << answer << std::endl;
  visited.clear();
}
