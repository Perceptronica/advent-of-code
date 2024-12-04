#include <bits/stdc++.h>

std::vector<std::vector<char>> matrix(0, std::vector<char>(0));

int32_t check(std::vector<std::vector<char>>& X) {
    std::vector<char> c1 = {X[0][0], X[1][1], X[2][2]};
    std::vector<char> c2 = {X[0][2], X[1][1], X[2][0]};
    std::string diag_1(c1.begin(), c1.end());
    std::string diag_2(c2.begin(), c2.end());
    return (diag_1 == "MAS" || diag_1 == "SAM") && (diag_2 == "MAS" || diag_2 == "SAM");
}

int32_t parse() {
    int32_t acc{0};
    std::size_t m_sz = matrix.size();
    std::vector<std::vector<char>> current(3, std::vector<char>(3));
    for (std::size_t i = 0; i < m_sz - 2; ++i) {
        for (std::size_t j = 0; j < m_sz - 2; ++j) {
            for (std::size_t I = 0; I < 3; ++I) {
                for (std::size_t J = 0; J < 3; ++J) {
                    current[I][J] = matrix[i + I][j + J];
                }
            }
            acc += check(current);
        }
    }
    return acc;
}

int main(int argc, char* argv[]) {
    std::string input = "../sample_tests/day_04.input";
    if (argc > 1) {
        input = argv[1];
    }

    std::fstream file(input);
    std::string line;
    while (std::getline(file, line)) {
        matrix.push_back({});
        for (const char& c : line) {
            matrix[matrix.size() - 1].push_back(c);
        }
    }

    int32_t answer{parse()};
    std::cout << answer << std::endl;
}
