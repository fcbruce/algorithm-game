/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 29 Sep 2015 04:57:19 PM CST
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

const int maxn = 107;
const int maxm = 0;

double dp[maxn][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int a, b, n;
    scanf("%d/%d %d", &a, &b, &n);
    double p = (double) a / b;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1; 
    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; (double)j/i < p + eps; j++)
      {
        dp[i][j] += dp[i-1][j] * (1 - p);
        if (j > 0) dp[i][j] += dp[i-1][j-1] * p;
      }
    }
    double P = 0;
    for (int j = 0; (double)j/n < p + eps; j++) P += dp[n][j];
    printf("Case #%d: %d\n", ++__, (int)(1.0 / P));
  }




  return 0;
}
