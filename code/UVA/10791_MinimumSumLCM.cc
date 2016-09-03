/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Sep 2016 09:44:59
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

LL sum(LL n)
{
  LL res = 0;
  int cnt = 0;
  for (LL i = 2; sqr(i) <= n; i++)
  {
    if (n % i == 0)
    {
      int factor = 1;
      while (n % i == 0)
      {
        factor *= i;
        n /= i;
      }
      cnt++;
      res += factor;
    }
  }
  if (n != 1) 
  {
    res += n;
    cnt++;
  }
  while (cnt < 2) 
  {
    res++;
    cnt++;
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  LL n;
  int __ = 0;

  while (scanf(lld, &n) == 1 && n > 0)
  {
    printf("Case %d: " lld "\n", ++__, sum(n));
  }





  return 0;
}
