/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 13 Jul 2015 01:42:30 PM CST
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

long long dp[20][10][2];
int digit[20];

long long dfs(int pos, int pre, bool top, bool nonzero, bool exist)
{
  int flag = exist ? 1 : 0;
  if (pos == -1) return exist ? 1 : 0;
  if (!top && nonzero && dp[pos][pre][flag] != -1) return dp[pos][pre][flag];
  int r = top ? digit[pos] : 9;
  long long res = 0ll;
  for (int i = 0; i <= r; i++) 
    res += dfs(pos-1, i, top && i == r, nonzero || i != 0, exist || pre == 4 && i == 9);
  if (!top && nonzero) return dp[pos][pre][flag] = res;
  return res;
}

long long calc(long long x)
{
  if (x == 0ll)  return 0ll;
  int pos = 0;
  while (x != 0ll)
  {
    digit[pos++] = x % 10;
    x /= 10;
  }
  return dfs(pos-1, 0, true, false, false);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(dp,-1,sizeof dp);

  int T_T;
  scanf("%d",&T_T);

  while (T_T--) 
  {
    long long n;
    scanf(lld, &n);
    printf(lld "\n", calc(n));
  }



  return 0;
}
