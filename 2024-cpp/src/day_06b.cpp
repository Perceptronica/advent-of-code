#include <bits/stdc++.h>
#include <cstdint>

struct dPos {
    uint8_t row;
    uint8_t col;
    dPos(const uint8_t row = 0, const uint8_t col = 0) : row (row), col(col) {}

    bool operator==(const dPos& p) const {
        return p.row == row && p.col == col;
    }

    // ...
};

int main(int argc, char* argv[]) {
    std::string input = "../sample_tests/day_06.input";
    if (argc > 1) {
        input = argv[1];
    }

    std::fstream file(input);
    std::string line;
    std::vector<std::string> map;

    while(std::getline(file, line)) {
        map.push_back(line);
    }

    int32_t x, y, answer{0};
    for (std::size_t i = 0; i < map.size(); ++i) {
        for (std::size_t j = 0; j < map[i].length(); ++j) {
            if (map[i][j] == '^') {
                x = static_cast<int32_t>(i);
                y = static_cast<int32_t>(j);
                break;
            }
        }
    }

    std::cout << answer << std::endl;
}
