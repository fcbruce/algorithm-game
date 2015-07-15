/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 15 Jul 2015 02:49:32 PM CST
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

long long dp[10][13][10][2];
int digit[10];

long long dfs(int pos, int remain, int pre, bool top, int exist)
{
  if (pos == -1) return remain == 0 && exist ? 1 : 0;
  if (!top && dp[pos][remain][pre][exist] != -1) return dp[pos][remain][pre][exist];
  int r = top ? digit[pos] : 9;
  long long res = 0ll;
  for (int i = 0; i <= r; i++) 
    res += dfs(pos - 1, (remain * 10 + i) % 13, i, top && i == r, exist || pre == 1 && i == 3);
  if (!top) dp[pos][remain][pre][exist] = res;
  return res;
}

long long calc(long long x)
{
  int pos = 0;
  while (x != 0ll)
  {
    digit[pos++] = x % 10;
    x /= 10;
  }
  return dfs(pos - 1, 0, 0, true, 0);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(dp, -1, sizeof dp);

  long long n;

  while (scanf(lld, &n) == 1)
    printf(lld "\n", calc(n));



  return 0;
}
