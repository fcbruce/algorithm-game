/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 19 Aug 2015 08:54:41 PM CST
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 233333
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm], v[maxm], nex[maxm];
int e_max;

int w[maxn], d[maxn];
int dp[2][maxn];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

int dfs(int s)
{
  if (dp[0][s] != -1) return dp[0][s];

  dp[0][s] = 0;
  dp[1][s] = INF;
  
  for (int e = fir[s]; ~e; e = nex[e])
  {
    dfs(v[e]);
    dp[0][s] = max(dp[0][s], dp[1][v[e]]);
    dp[1][s] = min(dp[1][s], dp[0][v[e]]);
  }

  if (dp[1][s] == INF) dp[1][s] = 0;
  dp[1][s] += w[s];
  return dp[0][s] += w[s];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n, m, k;

  while (scanf("%d%d%d", &n, &m, &k) == 3)
  {
    e_max = 0;
    memset(fir, -1, sizeof fir);

    memset(d, 0, sizeof d);

    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    for (int i = 0, u, v; i < m; i++)
    {
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      d[v]++;
    }

    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int i = 1; i <= n; i++) if (d[i] == 0) 
    {
      res = dfs(i);
      break ;
    }
    puts(res < k ? "Glory" : "Victory");
  }



  return 0;
}
