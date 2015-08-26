/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 26 Aug 2015 09:30:53 AM CST
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

#define maxm 
#define maxn 100007

using namespace std;

long long minv[maxn<<2];

void update(int p, int v, int k, int l, int r)
{
  if (l + 1 == r)
  {
    minv[k] = v;
    return ;
  }

  int m = l + r >> 1;
  if (p < m) update(p, v, k * 2 + 1, l, m);
  else update(p, v, k * 2 + 2, m, r);

  minv[k] = min(minv[k * 2 + 1], minv[k * 2 + 2]);
}

long long query(int a, int b, int k, int l, int r)
{
  if (b <= l || r <= a) return 1ll<<55;
  if (a <= l && r <= b) return minv[k];
  return min(query(a, b, k * 2 + 1, l, l + r >> 1), query(a, b, k * 2 + 2, l + r >> 1, r));
}

int type[maxn], e[maxn], le[maxn], pos[maxn];
long long dp[maxn];
int q[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    memset(pos, -1, sizeof pos);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", type + i);
      le[i] = pos[type[i]];
      pos[type[i]] = i;
    }
    for (int i = 0; i < n; i++) scanf("%d", e + i);

    int f = 0, r = -1;

    for (int i = 0; i < n; i++)
    {
      dp[i] = 1ll << 55;
      while (f <= r && e[q[r]] <= e[i]) r--;

      q[++r] = i;

      for (int j = upper_bound(q + f, q + r + 1, le[i]) - q; j <= r; j++)
      {
        if (le[i] == -1) 
        {
          if (j == f) dp[i] = min(dp[i], 0ll + e[q[j]]);
          else dp[i] = min(dp[i],dp[q[j]]);
        }
        else if (j > f && le[i] < q[j - 1]) dp[i] = min(dp[i], query(q[j - 1], q[j], 0, 0, n) + e[q[j]]);
        else dp[i] = min(dp[i], query(le[i], q[j], 0, 0, n) + e[q[j]]);
      }

      update(i, dp[i], 0, 0, n);
    }

    printf(lld "\n",dp[n - 1]);
  }

  return 0;
}
