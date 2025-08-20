#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define str string
#define el "\n"
#define ii pair<int,int>

using namespace std;

const ll MOD = 1e9+7;
const ll inf = 1e18;
const ll base = 131;
const ll maxn = 1e5+100;

int n, q;
int c[maxn];
vector<int> a[maxn];

ll f[maxn];
map<int,int> save[maxn];

int spf[maxn];

void sieve(int N = 100000) {
    for (int i = 2; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void tsnt(int id, int val) {
    while (val > 1) {
        int p = spf[val];
        int cnt = 0;
        while (val % p == 0) {
            val /= p;
            cnt++;
        }
        save[id][p] += cnt;
    }
}


void dfs(int u, int par){
    for(int &v: a[u]){
        if (v == par) continue;
        dfs(v, u);
        if ((int)save[u].size() < (int)save[v].size()) swap(save[u], save[v]);
        for(auto x: save[v]) save[u][x.fi] += x.se;
    }

    f[u] = 1;
    for(auto x: save[u]) {
        f[u] = (f[u] % MOD * (x.se + 1) % MOD) %MOD;
    }
}

signed  main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    if (fopen("TREE.inp", "r")){
        freopen("TREE.inp", "r", stdin);
        freopen("TREE.out", "w", stdout);
    }

    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    sieve();

    for(int _=1; _<=n; ++_) tsnt(_, c[_]);

    dfs(1, 0);

    while (q--){
        int u; cin >> u;
        cout << f[u] << ' ';
    }
}