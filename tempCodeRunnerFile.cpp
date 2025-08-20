/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define endl           '\n'
#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long oo     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;

int f[N], g[N], dp[N];

void solve() {
   //Trie's solution here
   cin >> n;
   g[0] = 1;
   for (int i = 0; i <= n; ++i) {
      g[i + 1] += g[i];
      f[i + 2] += f[i];
      dp[i + 3] += dp[i];

      
      f[i + 2] += g[i];
      dp[i + 3] += g[i];

      g[i + 1] += f[i];
      dp[i + 3] += f[i];

      g[i + 1] += dp[i];
      f[i + 2] += dp[i];
      
   }


   cout << (dp[n] + f[n] + g[n]);
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