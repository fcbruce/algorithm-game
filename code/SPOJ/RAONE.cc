/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 15 Jul 2015 09:04:07 AM CST
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

long long dp[10][200];
int digit[10];

long long dfs(int pos, int diff, bool top)
{
  if (pos == -1) return diff == 1 ? 1 : 0;
  if (!top && dp[pos][diff + 100] != -1) return dp[pos][diff + 100];
  int r = top ? digit[pos] : 9;
  long long res = 0;
  int sign = (pos & 1) == 0 ? -1 : 1;
  for (int i = 0; i <= r; i++) res += dfs(pos - 1, diff + sign * i, top && i == r);
  if (!top) return dp[pos][diff + 100] = res;
  return res;
}

long long calc(long long x)
{
  if (x < 1) return 0;
  int pos = 0;
  while (x != 0)
  {
    digit[pos++] = x % 10;
    x /= 10;
  }
  return dfs(pos - 1, 0, true);
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
    long long l,r;
    scanf(lld lld, &l, &r);
    printf(lld "\n", calc(r) - calc(l - 1));
  }

  return 0;
}
