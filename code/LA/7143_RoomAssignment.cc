/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 09 Oct 2015 03:20:54 PM CST
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
#ifdef _WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0);
const double eps = 1e-10;

typedef long long LL;
typedef int itn;

const int maxn = 100007;
const int maxm = 0;

const long long mod = 1000000007ll;

long long dp[17][107];
long long c[17];
long long rest[17];

long long p[maxn];
long long inv[maxn];

long long gcd(long long a, long long b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  else
  {
    long long d = gcd(b, a % b, y, x);
    y -= x * (a / b);
    return d;
  }
}

long long inver(long long x)
{
  long long a, b;
  gcd(x, mod, a, b);
  a %= mod; a += mod; a %= mod;
  return  a;
}

inline long long com(int i, int j)
{
  return (p[i] * inv[j] % mod) * inv[i - j] % mod;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  p[0] = 1;
  for (int i = 1; i < maxn; i++) p[i] = p[i - 1] * i % mod;
  for (int i = 0; i < maxn; i++) inv[i] = inver(p[i]);

  while (T_T--)
  {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= m; i++) scanf(lld, c + i);

    int rest = n;
    c[0] = 0;

    memset(dp, 0, sizeof dp);
    dp[0][k] = 1;
    for (int i = 0; i < m; i++)
    {
      rest -= c[i];
      for (int j = 0; j <= k; j++) 
      { 
        if (rest < 2 * j) break;
        for (int x = 0; x <= j; x++)
        {
          for (int y = 0; y <= j - x; y++) if (c[i + 1] - 2 * x - y >= 0 && rest - 2 * j >= c[i + 1] - 2 * x - y)
          {
            long long add = dp[i][j] * com(j, x);
            add %= mod;
            add *= com(j - x, y);
            add %= mod;
            add *= com(rest - 2 * j, c[i + 1] - 2 * x - y);
            add %= mod;
            dp[i + 1][j - x - y] += add;
            dp[i + 1][j - x - y] %= mod;
          }
        }
      }
    }


    printf("Case #%d: " lld "\n", ++__, dp[m][0]);

  }




  return 0;
}
