// #include <iostream>
// #include <map>
// using namespace std;
// #include "atcoder/modint.hpp"
// using mint = atcoder::modint998244353;

// long long N;
// map<long long, mint> memo;
// mint dp(long long n) {
//     if (n >= N) return n == N ? 1 : 0;
//     if (memo.count(n)) return memo[n];
//     mint res = 0;
//     for (int i = 2; i <= 6; i++) res += dp(i * n);
//     return memo[n] = res / 5;
// }
// int main() {
//     cin >> N;
//     cout << dp(1).val() << "\n";
// }
