#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifndef Zang_LOCAL
#define debug(x...) "giORZang"
#else
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...) _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0) (MACRO, ##__VA_ARGS__)
#define out(x) #x " = " << x << "; "
#define debug(...) std::cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << std::endl
#endif

namespace {
    #define sz(x) int(x.size())
    #define bit(x, i) (((x) >> (i)) & 1)
    #define all(a)  (a).begin(), (a).end()
    #define rall(a) (a).rbegin(), (a).rend()
    #define Gint ([&]() { ll x; return std::cin >> x, x; } ())

    using ll = long long; 
    using ld = long double;

    template <class T1, class T2> 
    bool chMax(T1 &a, T2 b) { return a < b && (a = b, true); }
    template <class T1, class T2> 
    bool chMin(T1 &a, T2 b) { return b < a && (a = b, true); }
    template<class T1, class T2>
    std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
        return os << '{' << p.first << ", " << p.second << '}';
    }
    template <class T> using MaxHeap = std::priority_queue<T, std::vector<T>, std::less<T>>;
    template <class T> using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    template <class T, class = std::decay_t<decltype(*begin(std::declval<T>()))>, class = std::enable_if_t<!std::is_same<T, std::string>::value>>
    std::ostream &operator<<(std::ostream &os, const T &c) {
        os << '[';
        for (auto it = c.begin(); it != c.end(); ++it) {
            os << &", "[2 * (it == c.begin())] << *it;
        }
        return os << ']';
    }

    const ld eps = 1e-6, pi = acos(-1);
    const ll mod = 1e9 + 7, e30 = 1ll << 30, e60 = 1ll << 60;
}

using namespace std;

const int MAXN = 1e5 + 1;

vector<int> adj[MAXN], circle, sp;
bool visited[MAXN];



bool dfs(int u, int par) {
    visited[u] = true;
    sp.emplace_back(u);

    for (int &v: adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) {
                return true;
            }
        } else if (v != par) {
            circle.emplace_back(v);
            while (sp.back() != v) {
                circle.emplace_back(sp.back());
                sp.pop_back();
            }
            return true;
        }
    }
    return false;
}

int dis1(int st) {
    queue<pair<int, int>> q;
    q.push({st, 0});
    visited[st] = true;

    int res = 0;
    while (q.size()) {
        auto [u, d] = q.front();
        q.pop();

        for (int v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push({v, d+1});
                chMax(res, d+1);
            }
        }
    }
    return res;
}

int dis2(int st, int en) {
    queue<pair<int, int>> q;
    q.push({st, 0});
    visited[st] = true;

    while (q.size()) {
        auto [u, d] = q.front();
        q.pop();

        for (int v: adj[u]) {
            if (v == en) return d+1;

            if (!visited[v]) {
                visited[v] = true;
                q.push({v, d+1});
            }
        }
    }
    return 0;
}

signed main() {
    function<void(string)> fileio = [&](string Task) -> void {
        if (fopen((Task + ".inp").c_str(), "r")) {
            freopen((Task + ".inp").c_str(), "r", stdin);
            freopen((Task + ".out").c_str(), "w", stdout); 
        }
    }; fileio("");
    cin.tie(nullptr) -> sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 0);

    memset(visited, false, sizeof visited);
    sp.clear();

    for (int &v: circle) {
        visited[v] = true;
    }
    for (int u = 1; u <= n; u++) {
        if (visited[u]) {
            for (int v: adj[u]) {
                if (!visited[v]) {
                    sp.emplace_back(u);
                }
            }
        }
    }

    int d1 = 0, d2 = 0, v1, v2;
    for (int v: sp) {
        int dis = dis1(v);
        if (d1 < dis) {
            d1 = dis;
            v1 = v;
        } else if (d2 < dis) {
            d2 = dis;
            v2 = v;
        }
    }

    memset(visited, false, sizeof visited);
    int d3 = dis2(v1, v2);
    debug(d1, d2, d3);

    cout << d1 + d2 + sz(circle) - d3 + (!d1 || !d2 ? 0 : 1);

    fprintf(stderr, "\n=====\nUsed: %.f ms\n", 1000.0 * clock() / CLOCKS_PER_SEC);
    return (0 ^ 0);
}
