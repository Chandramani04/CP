// #include <ext/pb_ds/assoc_container.hpp>  // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>  // for less

// #include "bits/stdc++.h";
// using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     ordered_set;

// /*-------------------------------------------------------------------*/
// #define fastio()                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define int long long int
// #define pb emplace_back
// #define ff first
// #define ss second
// #define setbits __builtin_popcountll
// #define clz __builtin_clzll
// #define ctz __builtin_ctzll
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()
// #define reverse(x) (reverse(all(x)))
// #define pll pair<int, int>
// #define rep(i, a, n) for (int i = a; i < (n); ++i)
// #define repo(i, a, b) for (int i = a; i <= b; ++i)
// #define per(i, a, b) for (int i = a; i >= b; i--)
// #define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
// #define sorted(a) (sort((a).begin(), (a).end()))
// #define countx(v, x) (count(all(v), x))
// #define minel(a) (*min_element((a).begin(), (a).end()))
// #define maxel(a) (*max_element((a).begin(), (a).end()))
// #define maxidx(a) (max_element((a).begin(), (a).end()) - (a).begin())
// #define minidx(a) (min_element((a).begin(), (a).end()) - (a).begin())
// #define lb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
// #define ub(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
// #define vi vector<int>
// #define input(v, n) \
//     vi v(n);        \
//     for (auto& x : v) cin >> x;
// const int MOD = 1e9 + 7;
// // 48-57 -> 0-9
// // 65-90 -> A-Z
// // 97-122 -> a-z
// /*
//     size_t found = str.find(str1);
//     if (found != string::npos)
//     auto index = str.find(targetstr , starting index , ending index)
//     to find in while string
//     auto index = str.find(target)
//  v.insert->
// vector_name.insert(vector_name.begin() + 3, 100);
// int a  = 0b101 ;//print 5   to print the deciaml number from binary 0b(binary form)
// bitset<8>b(6);cout<<b<<endl; // deciaml to binary
// a+b = (a^b)+2(a&b)
// */
// bool sortbysec(const pair<int, int>& a,
//                const pair<int, int>& b) {
//     return (a.second < b.second);
// }
// int maxdigitprodcut(int n) {
//     if (n < 10) return max((int)1, n);
//     return max((n % 10) * maxdigitprodcut(n / 10), 9 * maxdigitprodcut(n / 10 - 1));
// }
// // sort(v.begin(), v.end(), sortbysec);
// int modadd(int a, int b, int m) {
//     a %= m;
//     b %= m;
//     return (a + b) % m;
// }
// int modmul(int a, int b, int m) {
//     a %= m;
//     b %= m;
//     return (a * b) % m;
// }
// int modsub(int a, int b, int m) {
//     a %= m;
//     b %= m;
//     return (a - b + m) % m;
// }
// // FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// #define MAXN 1000001
// int spf[MAXN];
// // Time Complexity : O(nloglogn)
// void get_spf() {
//     spf[1] = 1;
//     for (int i = 2; i < MAXN; i++) {
//         spf[i] = i;
//     }
//     for (int i = 4; i < MAXN; i += 2) {
//         spf[i] = 2;
//     }
//     for (int i = 3; i * i < MAXN; i++) {
//         if (spf[i] == i) {
//             for (int j = i * i; j < MAXN; j += i) {
//                 if (spf[j] == j) spf[j] = i;
//             }
//         }
//     }
// }
// // A O(log n) function returning primefactorization
// // by dividing by smallest prime factor at every step
// vector<int> get_prime_factors(int n) {
//     vector<int> ans;
//     while (n != 1) {
//         ans.push_back(spf[n]);
//         n /= spf[n];
//     }
//     return ans;
// }
// bool isPrime(int n) {
//     if (n <= 1) {
//         return false;
//     }
//     if (n <= 3) {
//         return true;
//     }
//     if (n % 2 == 0 || n % 3 == 0) {
//         return false;
//     }
//     for (int i = 5; i * i <= n; i = i + 6) {
//         if (n % i == 0 || n % (i + 2) == 0) {
//             return false;
//         }
//     }

//     return true;
// }
// int moduloMultiplication(int x, int y) {
//     int res = 1;
//     x = x % MOD;

//     while (y > 0) {
//         if (y & 1) {
//             res = (res * x) % MOD;
//         }

//         y = y >> 1;
//         x = (x * x) % MOD;
//     }
//     return res;
// }

// int modInverse(int n) {
//     return moduloMultiplication(n, MOD - 2);
// }

// int nCr(int n, int r) {
//     if (n < r) {
//         return 0;
//     }
//     if (r == 0) {
//         return 1;
//     }

//     int fac[n + 1];
//     fac[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         fac[i] = (fac[i - 1] * i) % MOD;
//     }

//     return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
// }
// int power(int a, int b) {  // binary exponentiaion
//     int ans = 1;
//     while (b) {
//         if (b & 1) ans *= a;
//         a *= a;
//         b = b >> 1;  // b/=2
//     }
//     return ans;
// }
// template <typename T>
// T floor(T a, T b) {
//     return a / b - (a % b && (a ^ b) < 0);
// }
// template <typename T>
// T ceil(T x, T y) {
//     return floor(x + y - 1, y);
// }

// template <typename T>
// void print(const T& arg) {
//     cout << arg << endl;
// }
// template <typename T>
// void print(T& v) {
//     for (auto& x : v) {
//         cout << x << " ";
//     }
//     cout << endl;
// }

// template <typename t1, typename t2>
// void print(map<t1, t2> mp) {
//     for (auto [x, y] : mp) {
//         cout << x << " " << y << endl;
//     }
// }
// template <typename T, typename... Args>
// void print(const T& first_parameter, const Args&... second_paramter) {
//     cout << first_parameter << ' ';
//     if (sizeof...(second_paramter)) print(second_paramter...);
// }
// vector<int> sieve(int n) {
//     int* arr = new int[n + 1]();
//     vector<int> vect;
//     for (int i = 2; i <= n; i++)
//         if (arr[i] == 0) {
//             vect.push_back(i);
//             for (int j = 2 * i; j <= n; j += i)
//                 arr[j] = 1;
//         }
//     return vect;
// }
// vi frequency(vi v) {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < sz(v); i++) {
//         mp[v[i]]++;
//     }
//     vi ans;
//     for (auto x : mp) {
//         ans.push_back(x.second);
//     }
//     return ans;
// }

// /*---------------------------Code Begins---------------------------------------*/
// int pre[100001], c[100001], s[100001];
// void solve() {
//     int n, q;
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++) cin >> c[i], pre[i] = pre[i - 1] + c[i], s[i] = s[i - 1] + (c[i] == 1 ? 2 : 1);
//     while (q--) {
//         int l, r;
//         cin >> l >> r;
//         if (l == r) {
//             cout << "NO\n";
//             continue;
//         }
//         if (pre[r] - pre[l - 1] < s[r] - s[l - 1])
//             cout << "NO\n";
//         else
//             cout << "YES\n";
//     }
// }
// signed main() {
//     fastio();

//     int testcase = 1;
//     cin >> testcase;
//     while (testcase--)
//         solve();
// }

#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------*/
void solve() {
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int pref[n + 1];
    int one[n + 1], other[n + 1];
    pref[0] = 0, one[0] = 0, other[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i];
        one[i] = one[i - 1] + (arr[i] == 1);
        other[i] = other[i - 1];
        if (arr[i] != 1) {
            other[i] += arr[i] - 1;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int actual_sum = pref[r] - pref[l - 1];
        int one_sum = one[r] - one[l - 1];
        int other_sum = other[r] - other[l - 1];
        if (one_sum > other_sum or l == r) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    // jitne 1 hain unko 2 krna hoga
    // jitne >1 hain unk 1 se decrease krna hoga

    // for (int i = 1; i <= n; i++) {
    //     cout << cnt_one[i] << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << prefix_without_one[i] << " ";
    // }
    // cout << endl;

    // lets say #1's from [l r] = x
    // total sum from [l r] = y
    // we have to increase all the 1's by 1 and make them 2
    // we have to decrease all the non 1's by 1
    // z = sum from [ l r ] s.t. no element is 1
    // we have to decrease x from z where x = #1's from [l r]
    // if x>z the we can't do it
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
