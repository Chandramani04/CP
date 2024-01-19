#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    int m = n;
    int on = n, om = m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m));
    int s = 1;
    

    int i, k = 0, l = 0;

    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            ans[k][i] = s++;
            // cout << a[k][i] << " ";
        }
        k++;

        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            ans[i][n - 1] = s++;
            // cout << a[i][n - 1] << " ";
        }
        n--;

        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                ans[m - 1][i] = s++;
                // cout << a[m - 1][i] << " ";
            }
            m--;
        }

        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                ans[i][l]= s++;
                // cout << a[i][l] << " ";
            }
            l++;
        }
    }
    n = on, m = om;
    // cout<<n<<" "<<m<<endl;
    for (int i = 0; i < on; i++) {
        for (int j = 0; j < om; j++) {
            if (i == (n) / 2 and j == (m) / 2) {
                cout << "T"
                     << " ";
            } else
                cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
