/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 10 Sep 2016 12:37:26
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

const int maxn = 200007;
const int maxm = 0;

std::set<std::pair<int, int> > edges;

std::queue<int> q[2];

int d[maxn];

void clear(std::queue<int> &q)
{
  while (!q.empty()) q.pop();
}

void bfs(int s)
{
  int x = 0;
  memset(d, -1, sizeof d);
  d[s] = 0;
  std::queue<int> Q;

  Q.push(s);

  while (!Q.empty())
  {
    int s = Q.front(); Q.pop();
    while (!q[x].empty())
    {
      int t = q[x].front(); q[x].pop();

      if (edges.count({s, t}) == 0)
      {
        d[t] = d[s] + 1;
        Q.push(t);
      }
      else
      {
        q[x ^ 1].push(t);
      }
    }
    x ^= 1;
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
    int n, m, s;
    scanf("%d%d", &n, &m);
    edges.clear();

    while (m--)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      edges.insert({u, v});
      edges.insert({v, u});
    }

    clear(q[0]);
    clear(q[1]);

    scanf("%d", &s);

    for (int i = 1; i <= n; i++) if (i != s) q[0].push(i);

    bfs(s);

    bool first  = true;
    for (int i = 1; i <= n; i++) if (i != s)
    {
      if (!first) putchar(' ');
      printf("%d", d[i]);
      first = false;
    }
    puts("");
  }




  return 0;
}
