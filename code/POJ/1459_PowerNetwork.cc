/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 25 Jan 2016 11:02:40 PM PST
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

const int maxn = 207;
const int maxm = 40007;


int fir[maxn];
int u[maxm], v[maxm], cap[maxm], flow[maxm], nex[maxm];
int e_max;

int iter[maxn], q[maxn], lv[maxn];

int n, np, nc, m;

inline void add_edge(int s, int t, int w)
{
  int &e = e_max;
  u[e] = s; v[e] = t; cap[e] = w;
  nex[e] = fir[u[e]]; fir[u[e]] = e++;
  u[e] = t; v[e] = s; cap[e] = 0;
  nex[e] = fir[u[e]]; fir[u[e]] = e++;
}

bool dinic_bfs(int s, int t)
{
  int f, r;
  memset(lv, -1, sizeof lv);
  lv[s] = 0;
  q[f = r = 0] = s;
  while (f <= r)
  {
    int x = q[f++];
    for (int e = fir[x]; ~e; e = nex[e]) if (lv[v[e]] < 0 && cap[e] > flow[e])
    {
      lv[v[e]] = lv[x] + 1;
      q[++r] = v[e];
    }
  }
  return lv[t] > -1;
}

int dinic_dfs(int s, int t, int f)
{
  if (s == t) return f;
  for (int &e = iter[s]; ~e; e = nex[e]) if (lv[v[e]] > lv[s] && cap[e] > flow[e])
  {
    int d = dinic_dfs(v[e], t, std::min(f, cap[e] - flow[e]));
    if (d > 0)
    {
      flow[e] += d;
      flow[e ^ 1] -= d;
      return d;
    }
  }
  return 0;
}

inline int max_flow(int s, int t)
{
  int total_flow = 0;
  memset(flow, 0, sizeof flow);
  while (dinic_bfs(s, t))
  {
    memcpy(iter, fir, sizeof fir);
    int f;
    while ((f = dinic_dfs(s, t, INF)) > 0)
      total_flow += f;
  }
  return total_flow;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  while (scanf("%d%d%d%d", &n, &np, &nc, &m) == 4)
  {
    int s = n, t = n + 1;
    memset(fir, -1, sizeof fir);
    e_max = 0;
    
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      scanf(" (%d,%d)%d", &u, &v, &w);
      add_edge(u, v, w);
    }

    for (int i = 0; i < np; i++)
    {
      int x, v;
      scanf(" (%d)%d", &x, &v);
      add_edge(s, x, v);
    }

    for (int i = 0; i < nc; i++)
    {
      int x, v;
      scanf(" (%d)%d", &x, &v);
      add_edge(x, t, v);
    }

    printf("%d\n", max_flow(s, t));
  }





  return 0;
}
