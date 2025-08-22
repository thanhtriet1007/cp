/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define endl           '\n'
#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long oo     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, l, r;
int a[N];



namespace sub1 {
    int prefix[N];

    void solve() {
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int sum = abs(prefix[j] - prefix[i - 1]);
                if (sum >= l && sum <= r) {
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }
}

namespace sub2
{
    int compress[N];
    void solve() {
        for (int i = 1; i <= n; ++i) {
            compress[i] = a[i];
            
        }
    }   
} // namespace sub2


void solve() {
   //Trie's solution here
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n <= 1000) sub1::solve();
    else sub2::solve();
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