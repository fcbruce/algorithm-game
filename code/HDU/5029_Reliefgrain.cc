/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 23 Sep 2015 11:01:21 AM CST
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

int size[maxn], fa[maxn], son[maxn], dep[maxn], top[maxn], pos[maxn], ref[maxn];
int cp;
int col[maxn], cov[maxn];

struct tag
{
  int p, v, c;
  bool operator < (const tag &rhs) const
  {
    return p < rhs.p;
  }
};

std::vector<tag> tags; 

inline void add_edge(itn s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void dfs(int s, int f, int d)
{
  size[s] = 1;
  dep[s] = d;
  son[s] = -1;
  fa[s] = f;
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != f)
  {
    dfs(v[e], s, d + 1);
    size[s] += size[v[e]];
    if (son[s] == -1 || size[son[s]] < size[v[e]]) son[s] = v[e];
  }
}

void split(int s, int tp)
{
  top[s] =tp;
  pos[s] = cp++;
  ref[pos[s]] = s;

  if (son[s] != -1) split(son[s], tp);
  for (int e = fir[s]; ~e; e = nex[e]) 
    if (v[e] != fa[s] && v[e] != son[s]) split(v[e], v[e]);
}

inline void detect(int x, int y, int z)
{
  while (top[x] != top[y])
  {
    if (dep[top[x]] > dep[top[y]]) std::swap(x, y);
    tags.push_back({pos[top[y]], z, 1});
    tags.push_back({pos[y] + 1, z, -1});
    y = fa[top[y]];
  }

  if (dep[x] > dep[y]) std::swap(x, y);
  tags.push_back({pos[x], z, 1});
  tags.push_back({pos[y] + 1, z, -1});
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, m;

  while (scanf("%d%d", &n, &m) == 2 && (n != 0 || m != 0))
  {
    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 1, u, v; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }

    cp = 0;
    dfs(1, -1, 0);
    split(1, 1);

    tags.clear();

    while (m--)
    {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      detect(x, y, z);
    }

    sort(tags.begin(), tags.end());

    std::priority_queue<std::pair<int, int> > q;

    memset(cov, 0, sizeof cov);
    memset(col, 0, sizeof col);

    for (int i = 0, j = 0; i < cp; i++)
    {
      while (j < tags.size() && tags[j].p <= i)
      {
        cov[tags[j].v] += tags[j].c;
        if (cov[tags[j].v] > 0) q.push({cov[tags[j].v], -tags[j].v});
        j++;
      }
      while (!q.empty() && col[ref[i]] == 0)
      {
        auto &tmp = q.top();
        if (cov[-tmp.second] != tmp.first) q.pop();
        else col[ref[i]] = -tmp.second;
      }
    }

    for (int i = 1; i <= n; i++) printf("%d\n", col[i]);
  }




  return 0;
}
