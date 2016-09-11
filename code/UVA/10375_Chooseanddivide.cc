/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 09 Sep 2016 19:19:46
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

const int maxn = 10007;
const int maxm = 0;

inline double get_com(int m, int n)
{
  double res = 1;
  for (int i = 1; i <= n; i++) res *= (m - i + 1.) / i;
  printf("%f\n", res);
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int p, q, r, s;

  while (scanf("%d %d %d %d", &p, &q, &r, &s) == 4)
  {
    double res = 1;
    for (int i = 1; i <= q || i <= s; i++) 
    {
      if (i <= q) res *= (p - i + 1.) / i;
      if (i <= s) res *= i / (r - i + 1.);
    }
    printf("%.5f\n", res);
  }




  return 0;
}
