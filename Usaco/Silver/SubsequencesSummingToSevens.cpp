#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 1;
int a[MAXN];
long long prf[MAXN];

int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prf[i] = prf[i - 1] + a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if ((prf[i] - prf[j]) % 7 == 0) {
                ans = max(ans, i - j);
                break;
            }
        }
    }
    cout << ans;
}