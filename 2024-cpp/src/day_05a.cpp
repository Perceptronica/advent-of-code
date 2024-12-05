#include <bits/stdc++.h>
#include <sstream>

std::map<int32_t, std::set<int32_t>> rules;
std::vector<std::vector<int32_t>> prompts;

int32_t solve() {
    std::vector<int32_t> corr_p_pos(0);
    int32_t acc{0};
    for (std::size_t i = 0; i < prompts.size(); ++i) {
        bool flag = true;
        for (std::size_t j = 0; j < prompts[i].size() - 1; ++j) {
            for (std::size_t k = j + 1; k < prompts[i].size(); ++k) {
                if (!rules[prompts[i][j]].count(prompts[i][k])) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            corr_p_pos.push_back(i);
        }
    }
    for (const auto& m : corr_p_pos) {
        // std::cout << m << std::endl;
        acc += prompts[m][prompts[m].size() / 2];
    }
    return acc;

}

int main(int argc, char* argv[]) {
    std::string input = "../sample_tests/day_05.input";
    if (argc > 1) {
        input = argv[1];
    }

    std::fstream file(input);

    int32_t a;
    int32_t b;
    std::string line;
    bool write_prompts = false;
    while (std::getline(file, line)) {
        if (line.empty()) {
            write_prompts = true;
            continue;
        }
        std::stringstream s(line);
        if (write_prompts) {
            std::string token;
            prompts.push_back({});
            while (std::getline(s, token, ',')) {
                prompts[prompts.size() - 1].push_back(std::stoi(token));
            }
        } else {
            char sep = '|';
            if (s >> a >> sep >> b) {
                rules[a].insert(b);
                rules[0].insert(a);
            }
        }
    }

    int32_t answer{solve()};
    std::cout << answer << std::endl;
}
