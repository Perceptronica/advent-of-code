#include <bits/stdc++.h>

void solve(std::string& s) {
    std::vector<std::pair<std::size_t, std::size_t>> v;
    for (std::size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        std::size_t k = static_cast<std::size_t>(c - 48);
        if (i % 2 == 0) {
            v.push_back(std::make_pair(k, 0));
        } else {
            v[v.size() - 1].second = k;
        }
    }
    std::vector<int32_t> res;
    int32_t amount = 0;
    for (std::size_t i = 0 ; i < v.size(); ++i) {
        for (std::size_t j = 0; j < v[i].first; ++j) {
            res.push_back(i + 1);
        }
        for (std::size_t j = 0; j < v[i].second; ++j) {
            res.push_back(0);
        }
        amount += v[i].first;
    }
    uint64_t answer = 0;
    std::size_t k = res.size() - 1;
    for (std::size_t i = 0; i < amount; ++i) {
        if (res[i] != 0) {
            answer += (res[i] - 1) * i;
        } else {
            while (res[k] == 0) {
                --k;
            }
            answer += (res[k] - 1) * i;
            --k;
        }
    }
    std::cout << answer << std::endl;
}

int main(int argc, char* argv[]) {
    std::string input = "../sample_tests/day_09.input";
    if (argc > 1) {
        input = argv[1];
    }

    std::fstream file(input);
    std::string s;
    std::getline(file, s);

    solve(s);
}
