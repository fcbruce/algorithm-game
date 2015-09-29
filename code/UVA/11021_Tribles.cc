/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 29 Sep 2015 04:19:59 PM CST
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

const int maxn = 1007;
const int maxm = 0;

double dp[maxn], p[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; i++) scanf("%lf", p + i);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
      dp[i] = 0;
      for (int j = 0; j < n; j++) dp[i] += p[j] * pow(dp[i-1], j);
    }
    printf("Case #%d: %.8f\n", ++__, pow(dp[m], k));
  }




  return 0;
}
