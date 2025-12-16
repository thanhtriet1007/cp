/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long
#define fu(i, l, r) for (int i = (l); i <= (r); ++i)
#define fd(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

int n;
vector<int> adj[N];

int cl[N];

void dfs(int u, int p)
{
    if (cl[u] == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (cl[p] == i)
                continue;
            cl[u] = i;
            break;
        }
    }
    int i = 1;
    for (int &v : adj[u])
    {
        if (v == p)
            continue;

        for (; i <= n; ++i) {
            if (i == cl[u] || i == cl[p]) continue;
            cl[v] = i;
            break;
        }
        ++i;
    }
    
    for (int &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

void solve()
{
    // Trie's solution here
    // i luv BN
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cl[0] = -1;
    dfs(1, 0);

    set<int>myset;

    for (int i = 1; i <= n; ++i) {
        myset.insert(cl[i]);
    }

    cout << (int)myset.size() << '\n';

    for (int i = 1; i <= n; ++i)
        cout << cl[i] << ' ';
}

#define TASK "test"

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}