/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 13 Jul 2015 03:17:05 PM CST
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

int dp[10][10];
int digit[10];

int dfs(int pos, int pre, bool top)
{
  if (pos == -1) return 1;
  if (!top && dp[pos][pre] != -1) return dp[pos][pre];
  int r = top ? digit[pos] : 9;
  int res = 0;
  for (int i = 0; i <= r; i++) if (!(i == 4 || pre == 6 && i==2))
    res += dfs(pos - 1, i, top && i == r);
  if (!top) return dp[pos][pre] = res;
  return res;
}

int calc(int x)
{
  if (x == 0) return 1;
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
  int l,r;
  
  while (scanf("%d%d", &l, &r) == 2)
  {
    if (l == 0 && r == 0) break;
    printf("%d\n", calc(r) - calc(l-1));
  }



  return 0;
}
