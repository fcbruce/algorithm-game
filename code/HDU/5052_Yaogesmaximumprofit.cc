/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 02 Oct 2015 08:00:05 PM CST
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

int size[maxn], fa[maxn], son[maxn], deep[maxn], pos[maxn], top[maxn];
itn cp;

struct Node
{
  int add, max, min, profit[2];
  //profit[0] from top to bottom
  //profit[1] from bottom to top
  Node()
  {
    max = 0;
    min = INF;
    profit[0] = profit[1] = 0;
  }
  void update(int v)
  {
    add += v;
    min += v;
    max += v;
  }
  Node update(Node l, Node r)
  {
    min = std::min(l.min, r.min);
    max = std::max(l.max, r.max);
    profit[0] = std::max(std::max(0, r.max - l.min), std::max(l.profit[0], r.profit[0]));
    profit[1] = std::max(std::max(0, l.max - r.min), std::max(l.profit[1], r.profit[1]));
    return *this;
  }
}node[maxn << 2];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void dfs(int s, int f, int d)
{
  size[s] = 1;
  fa[s] = f;
  deep[s] = d;
  son[s] = -1;
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != f)
  {
    dfs(v[e], s, d + 1);
    size[s] += size[v[e]];
    if (son[s] == -1 || size[son[s]] < size[v[e]]) son[s] = v[e];
  }
}

void split(int s, int tp)
{
  pos[s] = cp++;
  top[s] = tp;
  if (son[s] != -1) split(son[s], tp);
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != fa[s] && v[e] != son[s])
    split(v[e], v[e]);
}

inline void pushdown(int k)
{
  if (node[k].add > 0)
  {
    node[k * 2 + 1].update(node[k].add);
    node[k * 2 + 2].update(node[k].add);
    node[k].add = 0;
  }
}

inline void pushup(int k)
{
  node[k].update(node[k * 2 + 1], node[k * 2 + 2]);
}

void update(int a, int b, int v, int k, int l, int r)
{
  if (b <= l || r <= a) return ;
  if (a <= l && r <= b)
  {
    node[k].update(v);
    return ;
  }

  pushdown(k);
  update(a, b, v, k * 2 + 1, l, l + r >> 1);
  update(a, b, v, k * 2 + 2, l + r >> 1, r);
  pushup(k);
}

Node query(int a, int b, int k, int l, int r)
{
  if (b <= l || r <= a) return Node();
  if (a <= l && r <= b) return node[k];

  pushdown(k);
  return Node().update(query(a, b, k * 2 + 1, l, l + r >> 1), query(a, b, k * 2 + 2, l + r >> 1, r));
}

void update(int x, int y, int v)
{
  while (top[x] != top[y])
  {
    if (deep[top[x]] > deep[top[y]]) std::swap(x, y);
    update(pos[top[y]], pos[y] + 1, v, 0, 0, cp);
    y = fa[top[y]];
  }

  if (deep[x] > deep[y]) std::swap(x, y);
  update(pos[x], pos[y] + 1, v, 0, 0, cp);
}

int query(int x, int y)
{
  Node tmp[2];
  //tmp[0] from top to bottom
  //tmp[1] from bottom to top

  int tag = 0;
  
  while (top[x] != top[y])
  {
    if (deep[top[x]] > deep[top[y]])
    {
      std::swap(x, y);
      tag ^= 1;
    }

    tmp[tag].update(query(pos[top[y]], pos[y] + 1, 0, 0, cp), tmp[tag]);

    y = fa[top[y]];
  }

  if (deep[x] > deep[y])
  {
    std::swap(x, y);
    tag ^= 1;
  }
  
  tmp[tag].update(query(pos[x], pos[y] + 1, 0, 0, cp), tmp[tag]);

  return std::max(tmp[0].max - tmp[1].min, std::max(tmp[0].profit[0], tmp[1].profit[1]));
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
    memset(fir, -1, sizeof fir);
    e_max = 0;

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    for (int i = 1; i < n; i++)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }

    cp = 0;
    dfs(1, -1, 0);
    split(1, 1);

    memset(node, 0, sizeof node);
    for (int i = 1; i <= n; i++) update(pos[i], pos[i] + 1, w[i], 0, 0, cp);

    int Q;
    scanf("%d", &Q);

    while (Q--)
    {
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v);
      printf("%d\n", query(x, y));
      update(x, y, v);
    }
  }




  return 0;
}
