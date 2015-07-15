/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 15 Jul 2015 09:41:13 AM CST
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
#define maxn 

using namespace std;

const long long mod = 1000000007ll;

char l[55], r[55];

long long dp[55][55][55][55];

long long dfs(const char *s, int pos, int c3, int c6, int c9, bool top)
{
  if (pos == -1) return c3 > 0 && c3 == c6 && c6 == c9 ? 1 : 0;
  if (!top && dp[pos][c3][c6][c9] != -1) return dp[pos][c3][c6][c9];
  int r = top ? s[pos] - '0' : 9;
  long long res = 0ll;
  for (int i = 0; i <= r; i++)
  {
    res += dfs(s, pos - 1, i == 3 ? c3 + 1 : c3, i == 6 ? c6 + 1 : c6, i == 9 ? c9 + 1 : c9, top && i == r);
    res %= mod;
  }
  if (!top) return dp[pos][c3][c6][c9] = res;
  return res;
}

long long calc(char *s)
{
  int l = strlen(s);
  reverse(s,s+l);
  return dfs(s, l - 1, 0, 0, 0, true);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(dp, -1, sizeof dp);

  int T_T;
  scanf("%d", &T_T);

  while (T_T-->0)
  {
    scanf("%s %s", l, r);
    int len = strlen(l);
    if (l[len - 1] == '0')
    {
      while (len > 0 && l[len - 1] == '0') l[--len] = '9';
      l[--len]--;
    }
    else l[--len]--;

    printf(lld "\n", (calc(r) - calc(l) + mod) % mod);
  }


  return 0;
}
