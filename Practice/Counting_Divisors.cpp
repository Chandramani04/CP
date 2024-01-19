#include "bits/stdc++.h";
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define MAXN 1000001
const int MOD = 1e9 + 7;
int spf[MAXN];
// Time Complexity : O(nloglogn)
void get_spf() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> get_prime_factors(int n) {
    vector<int> ans;
    while (n != 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int moduloMultiplication(int x, int y) {
    int res = 1;
    x = x % MOD;

    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int modInverse(int n) {
    return moduloMultiplication(n, MOD - 2);
}

int nCr(int n, int r) {
    if (n < r) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}
int power(int a, int b) {  // binary exponentiaion
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b = b >> 1;  // b/=2
    }
    return ans;
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
/*-----------------------------------------------------------------*/

void solve() {
    int a, b;
    cin >> a >> b;
    cout << moduloMultiplication(a, b) << endl;
}
signed main() {
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
        solve();
}
