#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        ans += n / i - (i - 1);
    }
    cout << ans;
}