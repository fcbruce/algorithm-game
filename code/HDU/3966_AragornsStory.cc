/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 27 Aug 2015 08:17:41 AM CST
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

const int maxn = 50007;
const int maxm = 100007;

int fir[maxn], w[maxn];
int u[maxm], v[maxm], nex[maxm];
int e_max;

int size[maxn], deep[maxn], fa[maxn], son[maxn], pos[maxn], top[maxn];
int pc;

int add[maxn << 2];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void dfs(int s, int f, int d)
{
  size[s] = 1;
  deep[s] = d;
  fa[s] = f;
  son[s] = -1;

  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != f)
  {
    dfs(v[e], s, d + 1);
    size[s] += size[v[e]];
    if (son[s] == -1 || size[v[e]] > size[son[s]]) son[s] = v[e];
  }
}

void build(int s,int tp)
{
  pos[s] = pc++;
  top[s] = tp;
  if (son[s] != -1) build(son[s], tp);
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != fa[s] && v[e] != son[s])
    build(v[e],v[e]);
}

inline void pushdown(int k)
{
  if (add[k] == 0) return ;
  int lc = k * 2 + 1, rc = k * 2 + 2;
  add[lc] += add[k]; add[rc] += add[k];
  add[k] = 0;
}

void update(int a, int b, int v, int k, int l, int r)
{
  if (b <= l || r <= a) return ;
  if (a <= l && r <= b)
  {
    add[k] += v;
    return ;
  }

  pushdown(k);
  update(a, b, v, k * 2 + 1, l, l + r >> 1);
  update(a, b, v, k * 2 + 2, l + r >> 1, r);
}

int query(int p, int k, int l, int r)
{
  if (l + 1 == r) return add[k];
  
  pushdown(k);
  int m = l + r >> 1;
  if (p < m) return query(p, k * 2 + 1, l, m);
  else return query(p, k * 2 + 2, m, r);
}

void update(int l, int r, int v)
{
  while (top[l] != top[r])
  {
    if (deep[top[l]] > deep[top[r]]) std::swap(l, r);
    update(pos[top[r]], pos[r] + 1, v, 0, 0, pc);
    r = fa[top[r]];
  }

  if (deep[l] > deep[r]) std::swap(l, r);
  update(pos[l], pos[r] + 1, v, 0, 0, pc);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, m, p;

  while (scanf("%d%d%d", &n, &m, &p) == 3)
  {
    for (int i = 1; i <= n; i++) scanf("%d", w + i);

    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int u, v; m > 0; m--)
    {
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }

    pc = 0;
    dfs(1, -1, 0);
    build(1, 1);
    memset(add, 0, sizeof add);
    for (int i = 1; i <= n; i++) update(pos[i], pos[i] + 1, w[i], 0, 0, pc);

    while (p-- > 0)
    {
      char cmd;
      int l, r, v;
      scanf(" %c", &cmd);

      switch (cmd)
      {
        case 'I':
          scanf("%d%d%d", &l, &r, &v);
          update(l, r, v);
          break ;
        case 'D':
          scanf("%d%d%d", &l, &r, &v);
          update(l, r, -v);
          break;
        default:
          scanf("%d", &l);
          printf("%d\n", query(pos[l], 0, 0, pc));
      }
    }
  }




  return 0;
}
