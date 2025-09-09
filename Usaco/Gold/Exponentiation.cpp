#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int powMod(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    int res = powMod(a, b / 2);

    res = 1ll * res * res % mod;
    if (b & 1) {
        res = 1ll * res * a % mod;
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