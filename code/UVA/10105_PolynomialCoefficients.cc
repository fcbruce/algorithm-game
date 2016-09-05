/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 04 Sep 2016 10:58:41
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

int _com[16][16];
void init()
{
  memset(_com, 0, sizeof _com);

  _com[1][0] = _com[1][1] = 1;
  for (int i = 2; i < 16; i++)
  {
    _com[i][0] = 1;
    for (int j = 1; j <= i; j++) _com[i][j] = _com[i - 1][j - 1] + _com[i - 1][j];
  }
}

int com(int n, int m)
{
  return _com[n][m];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  init();

  int n, k;

  while (scanf("%d%d", &n, &k) == 2)
  {
    LL res = 1;
    for (int i = 0; i < k; i++)
    {
      int x;
      scanf("%d", &x);
      if (x)
      {
        res *= com(n, x);
        n -= x;
      }
    }
    printf(lld "\n", res);
  }



  return 0;
}
