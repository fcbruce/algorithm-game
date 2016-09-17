/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 17 Sep 2016 12:32:12
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

const int maxn = 4007;
const int maxm = 160007;

int fir[maxn];
int iter[maxn];
int q[maxm], lv[maxn];

int u[maxm], v[maxm], cap[maxm], flow[maxm], nex[maxm];
int e_max;

struct Edge
{
  int u, v, w;
}edge[maxm];
int e_cnt;

int d[maxn];

void add_edge(int s, int t, int c)
{
  int &e = e_max;
  u[e] = s; v[e] = t; cap[e] = c; 
  nex[e] = fir[u[e]]; fir[u[e]] = e++;
  u[e] = t; v[e] = s; cap[e] = 0; 
  nex[e] = fir[u[e]]; fir[u[e]] = e++;
}

int dinic_dfs(int s, int t, int f)
{
  if (s == t) return f;
  for (int &e = iter[s]; ~e; e = nex[e]) if (lv[v[e]] > lv[s] && cap[e] > flow[e])
  {
    int d = dinic_dfs(v[e], t, std::min(cap[e] - flow[e], f));
    if (d > 0)
    {
      flow[e] += d;
      flow[e ^ 1] -= d;
      return d;
    }
  }
  return 0;
}

bool dinic_bfs(int s, int t)
{
  int f, r;
  q[f = r = 0] = s;
  memset(lv, -1, sizeof lv);
  lv[s] = 0;
  while (f <= r)
  {
    int x = q[f++];
    for (int e = fir[x]; ~e; e = nex[e]) if (lv[v[e]] < 0 && cap[e] > flow[e])
    {
      lv[v[e]] = lv[x] + 1;
      q[++r] = v[e];
    }
  }
  return lv[t] != -1;
}

int max_flow(int s, int t)
{
  int total = 0;
  memset(flow, 0, sizeof flow);
  while (dinic_bfs(s, t))
  {
    int f;
    memcpy(iter, fir, sizeof fir);
    while ((f = dinic_dfs(s, t, INF)) > 0)
    {
      total += f;
    }
  }
  return total;
}

void bfs(int s)
{
  int f, r;
  memset(d, 0x3f, sizeof d);
  d[s] = 0;
  q[f = r = 0] = s;
  while (f <= r)
  {
    int x = q[f++];
    for (int e = fir[x]; ~e; e = nex[e]) if (d[v[e]] > d[x] + 1)
    {
      q[++r] = v[e];
      d[v[e]] = d[x] + 1;
    }
  }
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
    int n, m;
    scanf("%d%d", &n, &m);

    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add_edge(u, v, w);
    }

    bfs(1);

    e_cnt = 0;
    for (int e = 0; e < e_max; e++)
    {
      if (d[u[e]] + 1 == d[v[e]])
      {
        edge[e_cnt++] = {u[e], v[e], e & 1 ? cap[e ^ 1] : cap[e]};
      }
    }

    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 0; i < e_cnt; i++)
    {
      int u, v, w;
      u = edge[i].u;
      v = edge[i].v;
      w = edge[i].w;
      add_edge(u, v, w);
    }

    int s = 1, t = n;

    printf("%d\n", max_flow(s, t));
  }




  return 0;
}
