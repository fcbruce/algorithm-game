/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 26 Aug 2015 04:45:34 PM CST
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

#define maxm 100007
#define maxn 50007

int fir[maxn];
int w[maxn][30];
int d[maxn][30];
int u[maxm], v[maxm], nex[maxm];
int e_max;

int k;
long long p[30];

int q[maxn];
int size[maxn], balance[maxn], fa[maxn];
bool vis[maxn];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

int bfs_root(int s, int n)
{
  int f, r;
  q[f = r = 0] = s;
  fa[s] = -1;
  while (f <= r)
  {
    int x = q[f++];
    for (int e = fir[x]; ~e; e = nex[e]) if (!vis[v[e]] && v[e] != fa[x])
    {
      fa[v[e]] = x;
      q[++r] = v[e];
    }
  }

  int root = -1;
  for (int i = r; i >= 0; i--)
  {
    int x = q[i];
    size[x] = 1;
    balance[x] = 0;
    for (int e = fir[x]; ~e; e = nex[e]) if (!vis[v[e]] && v[e] != fa[x])
    {
      size[x] += size[v[e]];
      balance[x] = std::max(balance[x], size[v[e]]);
    }
    balance[x] = std::max(balance[x], n - size[x]);
    if (root == -1 || balance[x] < balance[root]) root = x;
  }
  return root;
}

long long hash(int r[30])
{
  long long res = 0;
  for (int i = 0; i < k; i++) res = res * 3 + r[i];
  return res;
}

long long need(long long h, int s)
{
  int r[30];
  for (int i = k - 1; i >= 0; i--)
  {
    r[i] = h % 3 - w[s][i];
    r[i] = 3 - r[i];
    r[i] %= 3;
    r[i] += 3;
    r[i] %= 3;
    h /= 3;
  }
  return hash(r);
}

long long calc(std::vector<long long> &data, int s)
{
  long long res = 0ll;
  std::sort(data.begin(), data.end());
  
  for (size_t i = 0; i < data.size(); i++)
  {
    if (data[i] == 0ll) res += 2;
    long long h = need(data[i], s);
    res += std::upper_bound(data.begin(), data.end(), h) - std::lower_bound(data.begin(), data.end(), h);
    if (h == data[i]) res--;
  }

  return res / 2;
}

long long divide(int s, int n)
{
  long long res = 0ll;

  int root = bfs_root(s, n);
  vis[root] = true;

  std::vector<long long> all;
  memcpy(d[root], w[root], sizeof w[root]);
  long long h = hash(d[root]);
  all.push_back(h);

  for (int e = fir[root]; ~e; e = nex[e]) if (!vis[v[e]])
  {
    int f, r;
    q[f = r = 0] = v[e];
    fa[v[e]] = root;
    for (int i = 0; i < k; i++) d[v[e]][i] = (d[root][i] + w[v[e]][i]) % 3;
    std::vector<long long> sub;
    long long h = hash(d[v[e]]);
    sub.push_back(h);
    all.push_back(h);
    while (f <= r)
    {
      int x = q[f++];
      for (int e = fir[x]; ~e; e = nex[e]) if (!vis[v[e]] && v[e] != fa[x])
      {
        q[++r] = v[e];
        fa[v[e]] = x;
        for (int i = 0; i < k; i++) d[v[e]][i] = (d[x][i] + w[v[e]][i]) % 3;
        long long h = hash(d[v[e]]);
        sub.push_back(h);
        all.push_back(h);
      }
    }
    res -= calc(sub, root);
    res += divide(v[e], size[v[e]]);
  }

  return res += calc(all, root);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d", &n) == 1)
  {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) scanf(lld, p + i);

    for (int i = 1; i <= n; i++)
    {
      memset(w[i], 0, sizeof w[i]);
      long long v;
      scanf(lld, &v);
      for (int j = 0; j < k; j++) while (v % p[j] == 0)
      {
        w[i][j]++;
        v /= p[j];
      }
      for (int j = 0; j < k; j++) w[i][j] %= 3;
    }

    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 1, u, v; i < n; i++)
    {
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
    }

    memset(vis, 0, sizeof vis);

    printf(lld "\n",divide(1, n));
  }



  return 0;
}
