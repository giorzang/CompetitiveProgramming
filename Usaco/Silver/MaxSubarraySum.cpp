#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
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

    long long min_prf = 0, ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, prf[i] - min_prf);
        min_prf = min(min_prf, prf[i]);
    }
    cout << ans;
}