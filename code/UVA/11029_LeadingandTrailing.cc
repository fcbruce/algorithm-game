/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Sep 2016 17:19:37
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

int power(LL n, LL k)
{
  int res = 1;
  int tmp = n % 1000;
  while (k)
  {
    if (k & 1)
    {
      res *= tmp;
      res %= 1000;
    }
    tmp *= tmp;
    tmp %= 1000;
    k >>= 1;
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    LL n, k;
    scanf(lld lld, &n, &k);
    int TTT = power(n, k);

    double lg = log(n) / log(10) * k;
    double f = lg - floor(lg);
    int LLL = pow(10, f) * 100;
    
    printf("%d...%03d\n", LLL, TTT);
  }





  return 0;
}
