/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long
#define fu(i, l, r)    for (int i = (l); i <= (r); ++i)
#define fd(i, r, l)    for (int i = (r); i >= (l); --i)
#define endl           '\n';

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

vector<int>adj[N];
int cl[N], ans[N]; 

void dfs(int u, int p) {
    //cout << u << endl;

    for (int i = 0; i < (int)adj[u].size() - 1; ++i) {
        int v = adj[u][i];
        int vv = adj[u][i + 1];
        if (cl[v] == cl[vv]) {
            ans[cl[v]] = 1;
        }
    }

    for (int &v : adj[u]) {
        if (v == p) continue;
        if (cl[u] == cl[v]) {
            ans[cl[v]] = 1;
        }
        if (cl[p] == cl[v]) {
            ans[cl[v]] = 1;
        }
        dfs(v, u);
    }
}

void solve() {
    //Trie's solution here
    //i luv BN
    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        cl[i] = 0;
        ans[i] = 0;
        adj[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        cin >> cl[i];
    }

    
    cl[0] = -1;

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        sort(adj[u].begin(), adj[u].end(), [](int x, int y) {
            return cl[x] < cl[y];
        });
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i];
    }


    cout << endl;
}

#define TASK "test"

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r")) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   int t = 1;
   cin >> t;
   while (t--)
   solve();
   return 0;
}