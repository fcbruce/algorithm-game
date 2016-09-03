/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Sep 2016 16:05:00
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

  int a, b, n;

  while (scanf("%d%d%d", &a, &b, &n) == 3)
  {
    if (n == 0) 
    {
      puts("success");
      continue;
    }
    char cx = 'A', cy = 'B';
    int va = 0, vb = 0;
    while (true)
    {
      if (va == 0)
      {
        va = a;
        printf("fill %c\n", cx);
      }
      int pour = std::min(va, b - vb);
      va -= pour;
      vb += pour;
      printf("pour %c %c\n", cx, cy);
      if (vb == n)
      {
        puts("success");
        break;
      }

      if (vb == b)
      {
        printf("empty %c\n", cy);
        vb = 0;
      }
    }
  }




  return 0;
}
