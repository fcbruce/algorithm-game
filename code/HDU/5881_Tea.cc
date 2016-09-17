/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 17 Sep 2016 15:06:57
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

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  long long l, r;
  
  while (scanf(lld lld, &l, &r) == 2)
  {
    if (r <= 1)
    {
      printf("%d\n", 0);
      continue;
    }
    if (r <= 2)
    {
      printf("%d\n", 1);
      continue;
    }

    if (l == 0ll)
    {
      printf(lld "\n", (r + 1) / 2);
      continue;
    }

    long long re =  r - l - 2;

    long long result = 2;

    if (re > 0)
    {
      result += re / 2;
    }

    printf(lld "\n", result);
    
  }




  return 0;
}
