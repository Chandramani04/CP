#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    // ab-> ba , bc -> cb
    // abc-> acb or bac
    // cb ->swap
    // if l[i] = r[i] i++
    // if ba needed , then from i to first occ b , no c should be there , and reverse whole substring from i to first occ b
    // if cb needed, reverse substring from i to 1st occ of C , and no a should be there
    // bcaabababc
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(i, j);
        if (a[j] == b[i])
            continue;
        while (j < n && a[j] == a[i])
            j++;
        if (j == n or a[j] != b[i]) {
            break;
        }
        int diff = a[i] - b[i];
        if (diff != -1)
            break;
        swap(a[i], a[j]);
    }
    if (a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}

/*
    while (i < n - 1) {
        if (s[i] == t[i]) {
            i++;
        } else {
            // kya needed hai , cb or bc
            string needed = "";
            needed += t[i] + t[i + 1];
            // if (needed != "cb" or needed != "ba") {
            //     cout << "NO" << endl;
            //     return;
            // }
            if (needed == "cb") {
                // s[i] = b must , till s[i]!=c -> i++ ,  if(s[i]==a)NO
                // reverse substring from i to 1st occ of c
                int j = i;
                while (j < n and s[j] != 'c') {
                    if (s[j] == 'a') {
                        // cout << "NO" << endl;
                        return;
                    }
                    j++;
                }
                if (j == n) {
                    // cout << "NO" << endl;
                    return;
                }
                reverse(s.begin() + i, s.begin() + j + 1);
            } else if (needed == "ba") {
                // s[i] = a must , till s[i]!=b -> i++ ,  if(s[i]==c)NO
                // reverse substring from i to 1st occ of b
                int j = i;
                while (j < n and s[j] != 'b') {
                    if (s[j] == 'c') {
                        // cout << "NO" << endl;
                        return;
                    }
                    j++;
                }
                if (j == n) {
                    // cout << "NO" << endl;
                    return;
                }
                reverse(s.begin() + i, s.begin() + j + 1);
            }
            i++;
        }
    }
*/