/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define endl           '\n'
#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long oo     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int lz[N * 4], st[N * 4];
int n;
int a[N], b[N];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int target) {
    if (l == r) {
        return l;
    }

    int mid = (l + r) >> 1;

    if (st[id * 2] >= target) {
        return get(id * 2, l, mid, target);
    }
    else return get(id * 2 + 1, mid + 1, r, target - st[id * 2]);
}

int convertPosition(int pos) {
    return get(1,1,n,pos);
}


void solve() {
    //Trie's solution here
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n - 1; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i) {
        update(1,1,n,i,1);
    }

    int ans = 0;

    for (int i = 1; i < n - 1; ++i) {
        int pos = convertPosition(b[i]);
        int pre = convertPosition(b[i] - 1);
        int nxt = convertPosition(b[i] + 1);
        ans += a[pos] * (a[pre] + a[nxt]);

        update(1,1,n,pos,0);

        //cout << pos << ' ' << pre << ' ' << nxt <<' ' << endl ;
    }

    cout << ans;
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
