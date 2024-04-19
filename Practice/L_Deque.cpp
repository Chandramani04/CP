#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
int arr[4000];

int taro = 0, jiro = 0;
int dp[3010][3010][2];
int f(int i, int j, int turn) {
    if (i > j) {
        return 0;
    }
    if (dp[i][j][turn] != -1) {
        return dp[i][j][turn];
    }
    if (turn) {
        int pick_left = arr[i] + f(i + 1, j, !turn);
        int pick_right = arr[j] + f(i, j - 1, !turn);
        return dp[i][j][turn] = max(pick_left, pick_right);
    } else {
        int pick_left = f(i + 1, j, !turn);
        int pick_right = f(i, j - 1, !turn);
        return dp[i][j][turn] = min(pick_left, pick_right);
    }
}


// VAL = X - Y 
// taro wants to maximize VAL
// jiro wants to minimize VAL

// X + Y = S 
// y = s - x 
// taro wants to maximize x- y = x-(s-x) = 2x - s
// jiro wants to minimize x - y = x - (s - x) = 2x - s
// s is a constant => taro wants to maximize x and jiro wants to minimize x


// dp[L][R][turn] = maximum value that can be obtained by the player whose turn is it in the range [L, R]

// // base case 
// dp[i][i][0] = arr[i]
// dp[i][i][1] = 0 // 2nd players picks it , so 1st player gets 0 value

// // transition 
// dp[i][j][0] = arr[i] + max(dp[i+1][j][1],dp[i+1][j][1])
// dp[i][j][1] = min(dp[i+1][j][0],dp[i+1][j][1])

// // ans 
// dp[0][n-1][0]*2 - sum(arr[0...n-1])

// // order of evaluation 

// RminusL =  1 to n - 1   // dif b/w R and L from 1 to n 
// l = 0 to l+r-l < n 


void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int t = f(0, n - 1, 1);
    int tsum = accumulate(arr, arr + n, 0ll);
    cout << t - (tsum - t) << endl;
    
}
signed main() {
    int testcase = 1;
    while (testcase--)
        solve();
}
