/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 16 Aug 2015 07:13:43 PM CST
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
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 107

using namespace std;

double g[maxn][maxn];
int pre[maxn];

void gauss(double a[][maxn], int n)
{
  for (int i = 0; i < n; i++)
  {
    int r = i;
    for (int j = i + 1; j < n; j++)
      if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
    if (r!=i) for (int j = 0; j <= n; j++) swap(a[r][j], a[i][j]);

    for (int k = i + 1; k < n; k++)
    {
      double f = a[k][i] / a[i][i];
      for (int j = i; j <= n; j++) a[k][j] -= f * a[i][j];
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
      a[i][n] -= a[j][n] * a[i][j];
    a[i][n] /= a[i][i];
  }
}

int root(int x)
{
  return x == pre[x] ? x : pre[x] = root(pre[x]);
}

inline bool same(int x, int y)
{
  return root(x) == root(y);
}

inline void merge(int x, int y)
{
  pre[root(y)] = root(x);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n, m;
  scanf("%d%d", &n, &m);

  memset(g, 0, sizeof g);

  for (int i = 0; i < n; i++) pre[i] = i;

  for (int i = 0, u, v, w; i < m; i++)
  {
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    merge(u, v);
    double G = 1.0 / w;
    g[u][v] -= G;
    g[v][u] -= G;
    g[u][u] += G;
    g[v][v] += G;
  }

  memset(g[n - 1], 0, sizeof g[n - 1]);
  g[0][n] = 1;
  g[n - 1][n - 1] = 1;

  vector<int> connet;
  for (int i = 0; i < n; i++) if (same(i, 0)) connet.push_back(i);
  connet.push_back(n);

  for (size_t i = 0; i < connet.size(); i++)
    for (size_t j = 0; j < connet.size(); j++)
      g[i][j] = g[connet[i]][connet[j]];

  gauss(g, connet.size() - 1);

  printf("%.2f\n", g[0][connet.size() - 1]);

  return 0;
}
