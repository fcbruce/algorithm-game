/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 07 Jan 2017 15:15:08
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

char g[8][8];

void read()
{
  for (int i = 0; i < 4; i++) scanf("%s", g[i]);
}

inline bool isX(int i, int j)
{
  return 0 <= i && i < 4 && 0 <= j && j < 4 && g[i][j] == 'x';
}

inline bool test(int i, int j)
{
  return isX(i - 1, j) && isX(i + 1, j)
        || isX(i, j - 1) && isX(i, j + 1)
        || isX(i - 1, j - 1) && isX(i + 1, j + 1)
        || isX(i - 1, j + 1) && isX(i + 1, j - 1)
        || isX(i - 1, j) && isX(i - 2, j)
        || isX(i + 1, j) && isX(i + 2, j)
        || isX(i, j - 1) && isX(i, j - 2)
        || isX(i, j + 1) && isX(i, j + 2)
        || isX(i - 1, j - 1) && isX(i - 2, j - 2)
        || isX(i + 1, j + 1) && isX(i + 2, j + 2)
        || isX(i - 1, j + 1) && isX(i - 2, j + 2)
        || isX(i + 1, j - 1) && isX(i + 2, j - 2);
}

bool ok()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (g[i][j] == '.' && test(i, j)) return true;
    }
  }
  return false;
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  read();

  puts(ok() ? "YES" : "NO");




  return 0;
}
