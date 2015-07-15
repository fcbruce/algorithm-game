/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 13 Jul 2015 07:02:39 PM CST
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

long long dp[20][20][2000];
int digit[20];

long long dfs(int pos, int mid, long long balance, bool top)
{
  if (pos == -1) return balance == 0 ? 1 : 0;
  if (!top && dp[pos][mid][balance + 1000] != -1) return dp[pos][mid][balance + 1000];
  int r = top ? digit[pos] : 9;
  long long res = 0ll;
  for (int i = 0; i <= r; i++)
    res += dfs(pos - 1, mid, balance + i * (pos - mid), top && i == r);
  if (!top) return dp[pos][mid][balance + 1000] = res;
  return res;
}

long long calc(long long x)
{
  if (x == -1ll) return 0;
  if (x == 0ll) return 1;
  int pos = 0;
  while (x != 0ll)
  {
    digit[pos++] = x % 10;
    x /= 10;
  }
  long long res = 0;
  for (int i = 0; i < pos; i++)
    res += dfs(pos - 1, i, 0, true);
  return res - pos + 1;
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
