/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Sep 2016 19:24:07
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

const int maxn = 20007;
const int maxm = 0;

int fir[maxn];
int u[maxn], v[maxn], w[maxn], nex[maxn];
int e_max;

int d[maxn];
int q[maxn];
bool vis[maxn];

char buffer[32];

inline void add_edge(int s, int t, int l)
{
  int e = e_max++;
  u[e] = s; v[e] = t; w[e] = l;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void bfs(int s)
{
  int f, r;
  memset(d, 0, sizeof d);
  memset(vis, false, sizeof vis);
  q[f = r = 0] = s;
  vis[s] = true;
  while (f <= r)
  {
    int x = q[f++];
    for (int e = fir[x]; ~e; e = nex[e]) if (!vis[v[e]])
    {
      d[v[e]] = d[x] + w[e];
      vis[v[e]] = true;
      q[++r] = v[e];
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  while (gets(buffer) != nullptr)
  {
    e_max = 0;
    memset(fir, -1, sizeof fir);

    int n = 0;
    do
    {
      int u, v, w;
      sscanf(buffer, "%d%d%d", &u, &v, &w);
      n = std::max(n, u);
      n = std::max(n, v);
      add_edge(u, v, w);
      add_edge(v, u, w);
    } while (gets(buffer) != nullptr && buffer[0]);


    bfs(1);
    int s = std::max_element(d + 1, d + 1 + n) - d;
    bfs(s);
    printf("%d\n", *std::max_element(d + 1, d + 1 + n));

  }




  return 0;
}
