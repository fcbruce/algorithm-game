/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 13 Jul 2015 10:39:02 AM CST
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
#define LL int
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

int dp[10][1<<14];
int digit[20];

int dfs(int pos, int remain, bool top)
{
  if (remain < 0) return 0;
  if (pos == -1) return 1;
  if (!top && dp[pos][remain] != -1)  return dp[pos][remain];
  int r = top ? digit[pos] : 9;
  int res = 0ll;
  for (int i = 0; i <= r; i++) res += dfs(pos - 1, remain - i * (1 << pos), top && i == r);
  if (!top) return dp[pos][remain] = res;
  return res;
}

int calc(int a, int b)
{
  int pos = 0;
  while (a != 0)
  {
    digit[pos++] = a % 10;
    a /= 10;
  }
  pos--;
  while (pos != -1)
  {
    a += digit[pos] * (1 << pos);
    pos--;
  }
  pos = 0;
  while (b != 0) 
  {
    digit[pos++] = b % 10;
    b /= 10;
  }
  return dfs(pos - 1, a, true);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(dp, -1, sizeof dp);
  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int a,b;
    scanf(lld lld,&a,&b);
    printf("Case #%d: %d\n",++__,calc(a,b));
  }



  return 0;
}
