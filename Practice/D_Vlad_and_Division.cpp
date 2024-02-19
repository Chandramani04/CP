#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> ii() {
    std::vector<int> result;
    std::string input;
    std::getline(std::cin, input);
    size_t pos = 0;
    while ((pos = input.find(' ')) != std::string::npos) {
        result.push_back(std::stoi(input.substr(0, pos)));
        input.erase(0, pos + 1);
    }
    result.push_back(std::stoi(input));
    return result;
}

const int mxn = 200010;
std::vector<int> SS(mxn, 0);

int dp(int n) {
    int ans = 0;
    for (char digit : std::to_string(n)) {
        ans += digit - '0';
    }
    return ans;
}

int main() {
    for (int i = 0; i < mxn - 1; ++i) {
        SS[i + 1] = dp(i + 1) + SS[i];
    }

    std::vector<int> input = ii();
    for (int t = 0; t < input[0]; ++t) {
        std::vector<int> M;
        std::vector<int> A = ii();
        std::unordered_map<int, int> C;

        int val = 2147483647;
        int ans = 0;
        for (int i : A) {
            if (C.find(i) == C.end()) {
                C[i] = 0;
            }
            if (C.find(val - i) == C.end()) {
                C[val - i] = 0;
            }

            if (C[val - i] > 0) {
                C[val - i] -= 1;
            } else {
                C[i] += 1;
                ans += 1;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
