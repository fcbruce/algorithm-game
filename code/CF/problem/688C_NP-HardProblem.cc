/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 04 Jul 2016 20:32:04
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

struct Edge
{
  int v;
  Edge *next;
}E[maxm];

int e_max;

Edge *fir[maxn];

int vis[maxn];

bool ok;
int colour[2];

inline void add_edge(int u, int v)
{
  Edge *e = &E[e_max++];
  e->v = v;
  e->next = fir[u]; fir[u] = e;
}

void dfs(int s, int color)
{
  vis[s] = color;
  colour[color]++;

  
  for (Edge *e = fir[s]; e != nullptr && ok; e = e->next)
  {
    if (vis[e->v] < 0) dfs(e->v, color ^ 1);
    else if (vis[e->v] == color) 
    {
      ok = false;
      return ;
    }
  }
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, m;

  scanf("%d%d", &n, &m);

  for (int i = 0; i <= n; i++) fir[i] = nullptr;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }

  memset(vis, -1, sizeof vis);

  ok = true;
  colour[0] = colour[1] = 0;

  for (int i = 1; i <= n && ok; i++)
    if (vis[i] < 0) dfs(i, 1);

  if (ok)
  {
    printf("%d\n", colour[0]);
    for (int i = 1; i <= n; i++) if (vis[i] == 0) printf("%d ", i);
    puts("");
    printf("%d\n", colour[1]);
    for (int i = 1; i <= n; i++) if (vis[i] == 1) printf("%d ", i);
    puts("");
  }
  else
  {
    puts("-1");
  }


  return 0;
}
