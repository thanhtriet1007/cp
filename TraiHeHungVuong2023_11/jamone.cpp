/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define endl           '\n'
#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long oo     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, m, k;
vector<ii>adj[N];

struct dat {
    int u, v, opt, nonOpt;
}edge[N];

bool cmp(dat a, dat b) { 
    return a.nonOpt - a.opt < b.nonOpt - b.opt;
}

int vis[N];

vector<int>d(1002, oo);

void dfs(int u) {
    for (auto [v, w] : adj[u]) {
        if (vis[v]) continue;
        if (d[v] > d[u] + w) {
            d[v] = d[u] + w;
            dfs(v);
        }
    }
}

void solve() {
   //Trie's solution here
    cin >> n >> m >> k;
    
    for (int i = 1; i <= m; ++i) {
        int u, v, w, q; cin >> u >> v >> w >> q;
        edge[i] = {u, v, w, q};
    }

    sort(edge + 1, edge + 1 + m, cmp);

    for (; k; k--) {
        int s, t; cin >> s >> t;
        int ans = oo;
        d.assign(n + 10, oo);
        for (int i = 1; i <= m; ++i) {
            auto [u, v, opt, nonOpt] = edge[i];
            adj[u].push_back({v, opt});
            adj[v].push_back({u, opt});
            //priority_queue<ii, vector<ii>, greater<ii>>pq;
            d[s] = 0;
            dfs(v);
            dfs(u);
            ans = min(ans, d[t] + nonOpt - opt);
        }
        d.assign(n + 10, oo);
        cout << ans << endl;
        for (int i = 1; i <= n; ++i) adj[i].clear();
    }
}



#define TASK "test"

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r")) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   solve();
   return 0;
}
