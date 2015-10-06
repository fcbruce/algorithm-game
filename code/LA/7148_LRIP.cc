/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 05 Oct 2015 03:05:01 PM CST
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

const int maxn = 100007;
const int maxm = 200007;

int D;

int fir[maxn], w[maxn];
int u[maxm], v[maxm], nex[maxm];
int e_max;

bool vis[maxn];

int size[maxn], balance[maxn], father[maxn];
int q[maxn];

struct pair
{
  int l, d;
}p[maxn];

std::vector<pair> dec[maxn], inc[maxn];

struct segmentTree
{
  static int pool[maxn * 80 << 2];
  static int size;

  int n;
  int *min = NULL;

  void build(int n)
  {
    this->n = n;
    min = pool + size;
    size += n << 2;
    memset(min, 0x3f, sizeof(int) * n << 2);
    update(1, 0);
  }

  void update(int p, int v)
  {
    update(p, v, 0, 0, n);
  }

  void update(int p, int v, int k, int l, int r)
  {
    if (l + 1 == r)
    {
      min[k] = std::min(min[k], v);
      return ;
    }

    int m = l + r >> 1;
    if (p < m) update(p, v, k * 2 + 1, l, m);
    else update(p, v, k * 2 + 2, m, r);

    min[k] = std::min(min[k * 2 + 1], min[k * 2 + 2]);
  }

  int query(int d)
  {
    return query(d, 0, 0, n);
  }

  int query(int d, int k, int l, int r)
  {
    if (l + 1 == r) return l;
    
    int lc = k * 2 + 1, rc = k * 2 + 2;
    if (min[rc] <= d) return query(d, rc, l + r >> 1, r);
    if (min[lc] <= d) return query(d, lc, l, l + r >> 1);

    return 1;
  }

}incseg[maxn], decseg[maxn];

int segmentTree::size = 0;
int segmentTree::pool[maxn * 80 << 2];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

int bfs(int s, int fa, int n)
{
  int f, r;
  int root = -1;
  q[f = r = 0] = s;
  father[s] = fa;
  while (f <= r)
  {
    itn x = q[f++];
    size[x] = 1;
    balance[x] = 0;
    for (int e = fir[x]; ~e; e = nex[e]) if (!vis[v[e]] && v[e] != father[x])
    {
      father[v[e]] = x;
      q[++r] = v[e];
    }
  }

  for (int f = r; f >= 0; f--)
  {
    int x = q[f];
    for (int e = fir[x]; ~e; e = nex[e]) if (!vis[v[e]] && v[e] != father[x])
    {
      size[x] += size[v[e]];
      balance[x] = std::max(balance[x], size[v[e]]);
    }
    balance[x] = std::max(n - size[x], balance[x]);
    if (root == -1 || balance[root] > balance[x]) root = x;
  }

  return root;
}

void solve(int s, int fa)
{
  int f, r;
  q[f = r = 0] = s;
  father[s] = fa;
  p[s].l = 1;
  p[s].d = 0;
  while (f <= r)
  {
    int x = q[f++];
    if (abs(p[x].d) > D) continue;
    for (int e = fir[x]; ~e; e = nex[e]) if (v[e] != father[x] && !vis[v[e]])
    {
      p[v[e]].l = 0;
      father[v[e]] = x;
      if (p[x].d >= 0)
      {
        if (w[x] >= w[v[e]])
        {
          p[v[e]] = p[x];
          p[v[e]].l++;
          p[v[e]].d += w[x] - w[v[e]];
          dec[s].push_back({p[v[e]].l, abs(p[v[e]].d)});
        }
      }
      if (p[x].d <= 0)
      {
        if (w[x] <= w[v[e]])
        {
          p[v[e]] = p[x];
          p[v[e]].l++;
          p[v[e]].d += w[x] - w[v[e]];
          inc[s].push_back({p[v[e]].l, abs(p[v[e]].d)});
        }
      }

      if (p[v[e]].l > 0) q[++r] = v[e];
    }
  }
}

int divide(int s, int fa, int n)
{
  int res = 1;
  int root = bfs(s, fa, n);
  vis[root] = true;
  int decl = 2, incl = 2;
  for (int e = fir[root]; ~e; e = nex[e]) if (!vis[v[e]])
  {
    int delta = w[root] - w[v[e]];
    inc[v[e]].clear();
    dec[v[e]].clear();
    if (abs(delta) > D) continue;
    solve(v[e], root);
    if (delta >= 0)
    {
      for (auto &p : dec[v[e]])
      {
        p.l++;
        p.d += delta;
        if (p.d > D) continue;
        decl = std::max(decl, p.l + 1);
      }
      dec[v[e]].push_back({2, delta});
      decl = std::max(decl, 3);
    }
    if (delta <= 0)
    {
      for (auto &p : inc[v[e]])
      {
        p.l++;
        p.d -= delta;
        if (p.d > D) continue;
        incl = std::max(incl, p.l + 1);
      }
      inc[v[e]].push_back({2, -delta});
      incl = std::max(incl, 3);
    }
  }

  decseg[root].build(decl);
  incseg[root].build(incl);

  for (int e = fir[root]; ~e; e = nex[e]) if (!vis[v[e]])
  {
    for (auto &p : dec[v[e]]) if (p.d <= D) res = std::max(res, incseg[root].query(D - p.d) + p.l - 1);
    for (auto &p : inc[v[e]]) if (p.d <= D) res = std::max(res, decseg[root].query(D - p.d) + p.l - 1);

    for (auto &p : dec[v[e]]) decseg[root].update(p.l, p.d);
    for (auto &p : inc[v[e]]) incseg[root].update(p.l, p.d);
  }

  for (int e = fir[root]; ~e; e = nex[e]) if (!vis[v[e]]) res = std::max(res, divide(v[e], root, size[v[e]]));

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    segmentTree::size = 0;
    int n;
    scanf("%d%d", &n, &D);

    for (int i = 1; i <= n; i++) scanf("%d", w + i);

    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 1, u, v; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }

    memset(vis, false, sizeof vis);

    printf("Case #%d: %d\n", ++__, divide(1, -1, n));
  }




  return 0;
}
