/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 16 Aug 2015 08:24:36 PM CST
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
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-16

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 16

using namespace std;

long double g[maxn][maxn];

long double det(long double a[maxn][maxn], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (fabs(a[i][i]) < eps) return 0;
    int r = i;
    for (int j = i + 1; j < n; j++)
      if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
    if (r != i) for (int j = 0; j <= n; j++) swap(a[r][j], a[i][j]);

    for (int k = i + 1; k < n; k++)
    {
      long double f = a[k][i] / a[i][i];
      for (int j = i; j <= n; j++) a[k][j] -= f * a[i][j];
    }
  }

  long double res = 1.0;
  for (int i = 0; i < n; i++) res *= a[i][i];

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, m;
    scanf("%d%d", &n, &m);

    memset(g, 0, sizeof g);

    for (int i = 0, u, v; i < m; i++)
    {
      scanf("%d%d", &u, &v);
      u--;
      v--;
      g[u][v] -= 1;
      g[v][u] -= 1;
      g[u][u] += 1;
      g[v][v] += 1;
    }

    printf("%.0Lf\n", fabs(det(g, n - 1)));

  }



  return 0;
}
