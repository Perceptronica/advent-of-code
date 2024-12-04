#include <bits/stdc++.h>

std::deque<char> buffer;
std::vector<std::vector<char>> matrix(0, std::vector<char>(0));

std::string g() {
    std::string s;
    for (const auto& c : buffer) {
        s += c;
    }
    return s;
}

int32_t check_buffer() {
    if (buffer.size() == 4) {
        std::string s = g();
        if (s == "XMAS" || s == "SAMX") {
            return 1;
        }
    }
    return 0;
}

void clear(std::deque<char> &q) {
    std::deque<char> empty;
    std::swap(q, empty);
}

void debug_print(std::deque<char>& q) {
    for (const auto& c : q) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;
}

int column_search() {
    int32_t acc{0};
    for (std::size_t i = 0; i < matrix[0].size(); ++i) {
        clear(buffer);
        for (std::size_t j = 0; j < matrix.size(); ++j) {
            buffer.push_back(matrix[j][i]);
            acc += check_buffer();
            if (buffer.size() == 4) {
                buffer.pop_front();
            }
        }
    }
    return acc;
}

int string_search(std::vector<std::vector<char>>& m) {
    int32_t acc{0};
    for (std::size_t i = 0; i < m.size(); ++i) {
        clear(buffer);
        for (std::size_t j = 0; j < m[i].size(); ++j) {
            buffer.push_back(m[i][j]);
            acc += check_buffer();
            if (buffer.size() == 4) {
                buffer.pop_front();
            }
        }
    }
    return acc;
}

int32_t diagonal_search() {
    std::size_t m_sz = matrix.size();
    std::vector<std::vector<char>> diag(2 * m_sz - 1, std::vector<char>(0));
    std::vector<std::vector<char>> anti(2 * m_sz - 1, std::vector<char>(0));
    for (std::size_t i = 0; i < matrix[0].size(); ++i) {
        for (std::size_t j = 0; j < matrix.size(); ++j) {
            anti[i + j].push_back(matrix[i][j]);
        }
    }
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        for (std::size_t j = 0; j < matrix[0].size(); ++j) {
            diag[i - j + m_sz - 1].push_back(matrix[i][j]);
        }
    }

    return string_search(diag) + string_search(anti);
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

    int32_t answer{0};
    answer += column_search();
    answer += string_search(matrix);
    answer += diagonal_search();
    std::cout << answer << std::endl;
}
