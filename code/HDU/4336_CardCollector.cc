/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 27 Aug 2015 08:16:46 PM CST
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

const int maxn = 0;
const int maxm = 0;

double p[20];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d", &n) == 1)
  {
    for (int i = 0; i < n; i++) scanf("%lf", p + i);
    double ex = 0;
    for (int s = 1; s < (1 << n); s++)
    {
      double P = 0;
      int c = 0;
      for (int i = 0; i < n; i++) if ((s & (1 << i)) != 0)
      {
        P += p[i];
        c++;
      }
      if ((c & 1) == 0) ex -= 1.0 / P;
      else ex += 1.0 / P;
    }
    printf("%.5f\n", ex);
  }




  return 0;
}
