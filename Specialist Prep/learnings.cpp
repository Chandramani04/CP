#include <bits/stdc++.h>
using namespace std;

// Given a Permutation ->  for each elements in the array find the length of longest continuous increasing subsequence
// for ex : for ele = 2 we want 2 3 4 5  as a subsequence ,  3 is must , 4 is must , 5 is must
// [2 1 3 5 4 ]
// 1 -> 1 3 5 => len = 3
// 2 -> 2 3 5 => len = 3
// 3 -> 3 5 => len = 2
// 4 -> 4 => len = 1
// 5 -> 5 => len = 1

// void solve1() {
//     vector<int> arr = {2, 1, 3, 5, 4};
//     int n = arr.size();
//     // store indexes
//     map<int, int> storeIndex;
//     for (int i = 0; i < n; i++) {
//         storeIndex[arr[i]] = i + 1;
//     }
//     vector<int> prefix(n + 1);
//     prefix[n] = 1;
//     for (int i = n - 1; i >= 1; i--) {
//         if (storeIndex[i] < storeIndex[i + 1]) {
//             prefix[i] = prefix[i + 1] + 1;
//         } else {
//             prefix[i] = 1;
//         }
//     }

//     // printing
//     for (int i = 1; i <= n; i++) {
//         cout << prefix[i] << " ";
//     }
//     cout << endl;
// }

/*.................................................................................*/

// PROBLEM = find number of intersecting intervals

// void solve() {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> interval(n);
//     for (int i = 0; i < n; i++) {
//         cin >> interval[i].first >> interval[i].second;
//     }
//     sort(interval.begin(), interval.end());
//     multiset<int> activeEndPoints;
//     int intersectingIntervals = 0;
//     for (int i = 0; i < n; i++) {
//         int l = interval[i].first, r = interval[i].second;
//         while (!(activeEndPoints.empty()) and *activeEndPoints.begin() < l) {
//             activeEndPoints.erase(activeEndPoints.begin());
//         }
//         intersectingIntervals += activeEndPoints.size();
//         activeEndPoints.insert(r);
//     }
//     cout << intersectingIntervals << endl;
// }

int main() {
    return 0;
}
