/*
    CONCEPT =>
   x element before....[i,i+1,i+2,i+3, i+k].... y elements after
   // range [i i+k] is sorted and continuous ie. elements are present in increasing order of index
   , if i = 3 , k = 3 , then 3 4 5 is present in increase order of index

   // so we don't need to sort that range , we have to apply operations on max(left side, right side)

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, i, j, ans;

    cin >> t;

    for (; t--;) {
        cin >> n;
        ans = n;
        ll a[n];

        ll pos[n + 1], len[n + 1];

        for (i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        len[n] = 1;

        for (i = n - 1; i >= 1; i--) {
            if (pos[i] < pos[i + 1]) {
                len[i] = len[i + 1] + 1;
            } else {
                len[i] = 1;
            }
        }

        for (i = 1; i <= n; i++) {
            ans = min(ans, max(i - 1, n - (i + len[i] - 1)));
        }

        cout << ans << "\n";
    }
}