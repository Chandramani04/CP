#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>  // for less

#include "bits/stdc++.h";
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

/*-------------------------------------------------------------------*/
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long int
#define pb emplace_back
#define ff first
#define ss second
#define setbits __builtin_popcountll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define reverse(x) (reverse(all(x)))
#define pll pair<int, int>
#define rep(i, a, n) for (int i = a; i < (n); ++i)
#define repo(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define sorted(a) (sort((a).begin(), (a).end()))
#define countx(v, x) (count(all(v), x))
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define maxidx(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define minidx(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define lb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define ub(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define vi vector<int>
#define input(v, n) \
    vi v(n);        \
    for (auto& x : v) cin >> x;
const int MOD = 1e9 + 7;
// 48-57 -> 0-9
// 65-90 -> A-Z
// 97-122 -> a-z
/*
    size_t found = str.find(str1);
    if (found != string::npos)
    auto index = str.find(targetstr , starting index , ending index)
    to find in while string
    auto index = str.find(target)
 v.insert->
vector_name.insert(vector_name.begin() + 3, 100);
int a  = 0b101 ;//print 5   to print the deciaml number from binary 0b(binary form)
bitset<8>b(6);cout<<b<<endl; // deciaml to binary
a+b = (a^b)+2(a&b)
*/
bool sortbysec(const pair<int, int>& a,
               const pair<int, int>& b) {
    return (a.second < b.second);
}
int maxdigitprodcut(int n) {
    if (n < 10) return max((int)1, n);
    return max((n % 10) * maxdigitprodcut(n / 10), 9 * maxdigitprodcut(n / 10 - 1));
}
// sort(v.begin(), v.end(), sortbysec);
int modadd(int a, int b, int m) {
    a %= m;
    b %= m;
    return (a + b) % m;
}
int modmul(int a, int b, int m) {
    a %= m;
    b %= m;
    return (a * b) % m;
}
int modsub(int a, int b, int m) {
    a %= m;
    b %= m;
    return (a - b + m) % m;
}
// FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int power(int a, int b) {  // binary exponentiaion
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b = b >> 1;  // b/=2
    }
    return ans;
}
template <typename T>
T floor(T a, T b) {
    return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
    return floor(x + y - 1, y);
}

template <typename T>
void print(const T& arg) {
    cout << arg << endl;
}
template <typename T>
void print(T& v) {
    for (auto& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename t1, typename t2>
void print(map<t1, t2> mp) {
    for (auto [x, y] : mp) {
        cout << x << " " << y << endl;
    }
}
template <typename T, typename... Args>
void print(const T& first_parameter, const Args&... second_paramter) {
    cout << first_parameter << ' ';
    if (sizeof...(second_paramter)) print(second_paramter...);
}
vector<int> sieve(int n) {
    int* arr = new int[n + 1]();
    vector<int> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0) {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
vi frequency(vi v) {
    unordered_map<int, int> mp;
    for (int i = 0; i < sz(v); i++) {
        mp[v[i]]++;
    }
    vi ans;
    for (auto x : mp) {
        ans.push_back(x.second);
    }
    return ans;
}

/*---------------------------Code Begins---------------------------------------*/

int lcs(string &s , string &v){
	int n = s.size(),m = v.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	
	for ( int i = 1 ;i<=n;i++){
		for ( int j = 1 ; j <= m ; j++ ) {
			if ( s[i-1]==v[j-1]) {
				dp[i][j] = 1 + dp [ i - 1 ] [j -1 ] ;
			}
			else dp[i][j] = max ( dp[i-1][j], dp[i][j-1] );
		}
	}
	return dp[n][m];
}

int lcs(string &s, string &v){
	int n = s.size() , m = v.size() ;
	int dp[n+1][m+1];
	memset(dp,0,sizeof dp);
	for ( int i = 1 ; i <= n; i++){
		for ( int j = 1; j <= m; j++){
			if ( s[i-1] == v[j-1] ) dp[i][j] = 1 + dp[i-1][j-1] ;
			else dp[i][j] = max ( dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c0 = count(all(s), '0'), c1 = count(all(s), '1');
    if (c1 != c0) {
        cout << -1 << endl;
        return;
    }

    deque<char> d;
    for (auto x : s) d.push_back(x);
    int del = 0, ns = n;
    vi ans;
    while (!d.empty()) {
        if (d.front() == d.back()) {
            if (d.front() == '0') {
                // 0  0
                d.push_back('0');
                d.push_back('1');
                ans.pb(ns - del);
                ns += 2;
            } else {
                // 1 1
                d.push_front('1');
                d.push_front('0');
                ans.pb(del);
                ns += 2;
            }
        } else {
            // 1 0 or 0 1
            d.pop_front();
            d.pop_back();
            del++;
        }
    }
    cout << sz(ans) << endl;

    print(ans);
}
signed main() {
    fastio();

    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
/*BS TEMPLET
int l,r;
l = 0;(assuming we have a 0 at l);
r = 1e9 ( assuming we have a 1 at r);
0-> false , 1 -> true;
while(r>l+1){
    int mid =  l + (r-l)/2;
    // if we have a 1 at mid ie
    if(check(mid)==true){
        r =mid ;
    }
    else l = mid;
}
print(l or r depeneding on what we need);
agr hme maximum chahiye to low ko expandkrenge -> if(check)low = mid krenge
agr minimum chahiye to high to shrink krenge -> high = mid
BIT TRICKS->
UC -> LC -> char('C' | ' '); // or with space
LC -> UC -> char('c' & '_'); // and with underscore
*/
/*
dp memoization using umap
unordered_map<(number of states/changing paramters),int>dp;
for ex -> unordered_map<pair<int,int>,int>dp; // here #state = 2 ,
inside rec function  ->
checking if current state is previosly calculated or not
if(dp.find({i,target})!=dp.end())return dp[{i,target}];
or we can use mp.count(target) function ->
if(dp.count({i,target}))return dp[{i,target}]
storing current state ->
dp[{i,target}] = include + exclude
*/
/* LIS in NLogN
vector<int>print_lis(vector<int>&v){
int n = v.size();
vector<int>temp;
temp.push_back(v[0]);
vector<int>lis;
for(int i = 0;i<n;i++){
if(lis.size()==0 or lis.back()<v[i]){
lis.push_back(v[i]);
}
else{
auto it = lower_bound(lis.begin(),lis.end(),v[i]);
*it = v[i];// or v[it-lis.begin()] = arr[i];
}
}
return lis;
}
*/
/*
rotation of matrix (0 based indexing)
arr[i][j] == arr[j][j-1-i] == arr[n-1-i][n-1-j] == arr[n-1-j][i]
*/
