#include <bits/stdc++.h>
using namespace std;

bool isPrime[100];
int dp[10][100][2];
vector<int> digits;

void sieve() {
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < 100; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * i; j < 100; j += i) {
            isPrime[j] = false;
        }
    }
}

int f(int pos, int sum, bool tight) {
    if (pos == digits.size()) {
        return isPrime[sum];
    }
    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }
    dp[pos][sum][tight] = 0;
    int limit = tight ? digits[pos] : 9;
    
    for (int d = 0; d <= limit; d++) {
        dp[pos][sum][tight] += f(pos + 1, sum + d, tight & (d == limit));
    }
    return dp[pos][sum][tight];
}

int calc(int n) {
    digits.clear();
    while (n) {
        digits.emplace_back(n % 10);
        n /= 10;
    }
    if (!digits.size()) {
        digits.emplace_back(0);
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof dp);
    return f(0, 0, true);
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    sieve();

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        
        cout << calc(r) - calc(l - 1) << '\n';
    }
}