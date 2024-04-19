#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, s;
    cin >> n >> s;
    if ((n > 1 and s == 0) or s > 9 * n) {
        cout << -1 << " " << -1 << endl;
        return;
    }
    if(n==1 and s==0){
        cout << 0 << " " << 0 << endl;
        return;
    }

    // make largest number whose sum of digits is s and number of digits is n
    string largest = "";
    int sum = s;
    for (int i = 0; i < n; i++) {
        int digit = min(sum, 9LL);
        largest += to_string(digit);
        sum -= digit;
    }

    // make smallest number whose sum of digits is s and number of digits is n
    string smallest = "";
    sum = s;
    for (int i = 0; i < n; i++) {
        int digit = min(sum, 9LL);
        smallest += to_string(digit);
        sum -= digit;
    }
    reverse(smallest.begin(), smallest.end());
    if (smallest[0] == '0') {
        smallest[0] = '1';
        for (int i = 1; i < n; i++) {
            if (smallest[i] != '0') {
                smallest[i]--;
                break;
            }
        }
    }
    cout << smallest << " ";
    cout << largest << endl;
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
