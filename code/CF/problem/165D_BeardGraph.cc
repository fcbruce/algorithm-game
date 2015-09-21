/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 21 Sep 2015 07:18:31 PM CST
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

int fir[maxn];
int u[maxm], v[maxm], nex[maxm];
int e_max;

int son[maxn], fa[maxn], size[maxn], pos[maxn], dep[maxn], top[maxn];
int cp;

int sum[maxn << 2];

struct Edge
{
  int u, v;
  void swap()
  {
    std::swap(u, v);
  }
}edge[maxn];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void dfs(int s, int d, int f)
{
  fa[s] = f;
  dep[s] = d;
  size[s] = 1;
  son[s] = -1;
  for (int e = fir[s]; ~e; e = nex[e]) if (f != v[e])
  {
    dfs(v[e], d + 1, s);
    size[s] += size[v[e]];
    if (son[s] == -1 || size[son[s]] > size[v[e]]) son[s] = v[e];
  }
}

void build(int s, int tp)
{
  pos[s] = cp++;
  top[s] = tp;
  if (son[s] != -1) build(son[s], tp);
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != fa[s] && v[e] != son[s])
    build(v[e], v[e]);
}

inline void pushup(int k)
{
  sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
}

void init(int k, int l, int r)
{
  if (l + 1 == r)
  {
    sum[k] = 1;
    return ;
  }

  init(k * 2 + 1, l, l + r >> 1);
  init(k * 2 + 2, l + r >> 1, r);

  pushup(k);
}

void update(int p, int v, int k, int l, int r)
{
  if (l + 1 == r)
  {
    sum[k] =v;
    return ;
  }

  int m = l + r >> 1;
  if (p < m) update(p, v, k * 2 + 1, l, m);
  else update(p, v, k * 2 + 2, m, r);

  pushup(k);
}

int query(int a, int b, int k, int l, int r)
{
  if (b <= l || r <= a) return 0;
  if (a <= l && r <= b) return sum[k];

  return query(a, b, k * 2 + 1, l, l + r >> 1) + query(a, b, k * 2 + 2, l + r >> 1, r);
}

int query(int x, int y)
{
  int res = 0;
  while (top[x] != top[y])
  {
    if (dep[top[x]] > dep[top[y]]) std::swap(x, y);
    int len = query(pos[top[y]], pos[y] + 1, 0, 0, cp);
    if (len != pos[y] + 1 - pos[top[y]]) return -1;
    res += len;
    y = fa[top[y]];
  }

  if (x != y)
  {
    if (dep[x] > dep[y]) std::swap(x, y);
    int len = query(pos[son[x]], pos[y] + 1, 0, 0, cp);
    if (len != pos[y] + 1 - pos[son[x]]) return -1;
    res += len;
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  e_max = 0;
  memset(fir, -1, sizeof fir);

  int n;
  scanf("%d", &n);

  for (int i = 1, u, v; i < n; i++)
  {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
    edge[i] = {u,v};
  }

  cp = -1;
  dfs(1, 0, -1);
  build(1, 1);
  for (int i = 1; i < n; i++)
    if (dep[edge[i].u] > dep[edge[i].v]) edge[i].swap();
  init(0, 0, cp);


  int m;
  scanf("%d", &m);

  while (m--)
  {
    int cmd;
    scanf("%d", &cmd);
    
    if (cmd == 3)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%d\n", query(u, v));
    }
    else if (cmd == 2)
    {
      itn k;
      scanf("%d", &k);
      update(pos[edge[k].v], 0, 0, 0, cp);
    }
    else
    {
      itn k;
      scanf("%d", &k);
      update(pos[edge[k].v], 1, 0, 0, cp);
    }
  }





  return 0;
}
