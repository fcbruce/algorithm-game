/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 02 Sep 2016 19:33:56
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

LL gcd(LL a, LL b, LL &x, LL &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }

  LL d = gcd(b, a % b, y, x);
  y -= x * (a / b);
  return d;
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    LL x, k;
    scanf(lld lld, &x, &k);
    LL a = x / k;
    LL b = x % k == 0 ? a : a + 1;
    LL x0, y0;
    LL d = gcd(a, b, x0, y0);
    printf(lld " " lld "\n", x / d * x0, x / d * y0);
  }




  return 0;
}
