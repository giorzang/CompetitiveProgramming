#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 1;
char c[MAXN][MAXN];
int prf[MAXN][MAXN];

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            prf[i][j] = prf[i - 1][j] + prf[i][j - 1] - prf[i - 1][j - 1] + (c[i][j] == '*');
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << prf[x2][y2] - prf[x1 - 1][y2] - prf[x2][y1 - 1] + prf[x1 - 1][y1 - 1] << '\n';
    }
}