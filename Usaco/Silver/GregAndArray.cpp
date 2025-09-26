#include <bits/stdc++.h>
using namespace std;

struct operation {
    int l, r, d;
};

const int MAXN = 1e5 + 2;

int a[MAXN], cnt_op[MAXN];
operation op[MAXN];
long long prf[MAXN];

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> op[i].l >> op[i].r >> op[i].d;
    }


    while (k--) {
        int x, y;
        cin >> x >> y;

        ++cnt_op[x];
        --cnt_op[y + 1];
    }
    for (int i = 1; i <= m; i++) {
        cnt_op[i] += cnt_op[i - 1];

        long long d = 1ll * op[i].d * cnt_op[i];
        prf[op[i].l] += d;
        prf[op[i].r + 1] -= d;
    }
    for (int i = 1; i <= n; i++) {
        prf[i] += prf[i - 1];
        cout << prf[i] + a[i] << ' ';
    }
}