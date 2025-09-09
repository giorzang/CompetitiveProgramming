#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int powMod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = 1ll * res * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << powMod(a, b) << '\n';
    }
}