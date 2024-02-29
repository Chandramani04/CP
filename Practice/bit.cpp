#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void set_bit(int &n, int pos) {
    n = n | (1 << pos);
    // 000100
    // 000010
    // 0/1
    // 1
}
void unset_bit(int &n, int pos) {
    // 0000100
    // 1111011
    n = n & (~(1 << pos));
}
void flip_bit(int &n, int pos) {
    // 000001100
    // 000001000
    // 1 -> 0
    // 0 -> 1
    n = n ^ (1 << pos);
    //  11100
    //  00100
    // xor = 11000

    //  11011
    //  00100
    // xor = 11111
}
int check_setbit(int n, int pos) {
    bool bit_at_pos = n & (1 << pos);
    return bit_at_pos;
}
int power_of_two(int n) {
    // 001000
    // n & n -1
    int bit = n & (n - 1);
    return bit == 0;
}
void solve() {
    int n;
    cin >> n;
    // 8 =  001000
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
