#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 1;
int a[MAXN];
long long prf[MAXN];

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << prf[r] - prf[l] << '\n';
    }
}