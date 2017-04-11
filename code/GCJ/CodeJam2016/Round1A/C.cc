/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Apr 2017 22:24:54
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

const int maxn = 1024;
const int maxm = 0;

int deep[maxn];
int bff[maxn];
int in_deg[maxn];
int length[maxn];
int circle;

void dfs(int root, int s, int d)
{
  deep[s] = d;
  if (deep[bff[s]] == -1) dfs(root, bff[s], d + 1);
  else if (deep[bff[s]] == d - 1)
  {
    length[s] = std::max(length[s], d);
  }
  else
  {
    circle = std::max(circle, d - deep[bff[s]] + 1);
  }
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    memset(in_deg, 0, sizeof in_deg);
    for (int i = 1; i <= n; i++) 
    {
      scanf("%d", bff + i);
      in_deg[bff[i]]++;
    }

    memset(length, 0, sizeof length);
    circle = 0;
    for (int i = 1; i <= n; i++) 
    {
      memset(deep, -1, sizeof deep);
      dfs(i, i, 0);
    }

    for (int i = 1; i <= n; i++) if (bff[i] > 0)
    {
      if (bff[bff[i]] == i)
      {
        length[i] += length[bff[i]];
        length[bff[i]] = 0;
        bff[i] = -1;
      }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res += length[i];

    res = std::max(res, circle);
    if (res == 0) res = n;
    printf("Case #%d: %d\n", ++__, res);
  }




  return 0;
}
