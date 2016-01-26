/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 26 Jan 2016 03:29:00 AM PST
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

const int maxn = 505;
const int maxm = 404040;

int fir[maxn];
int u[maxm], v[maxm], w[maxm], nex[maxm];
int e_max;

int q[maxm << 3];
std::pair<int, int> d[maxn];
int score[maxn];
bool inq[maxn];

inline void add_edge(int s, int t, int c)
{
  int e = e_max++;
  u[e] = s; v[e] = t; w[e] = c;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void SPFA(int s)
{
  int f, r;
  memset(d, 0x3f, sizeof d);
  memset(inq, false, sizeof inq);
  d[s] = {0, score[s]};
  q[f = r = 0] = s;

  while (f <= r)
  {
    auto s = q[f++];
    inq[s] = false;
    for (int e = fir[s]; ~e; e = nex[e])
    {
      auto next = d[s];
      next.first += w[e];
      next.second += score[v[e]];
      if (next < d[v[e]])
      {
        d[v[e]] = next;
        if (!inq[v[e]])
        {
          q[++r] = v[e];
          inq[v[e]] = true;
        }
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);

  memset(fir, -1, sizeof fir);
  e_max = 0;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", score + i);
    score[i] = -score[i];
  }

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edge(u, v, w);
    add_edge(v, u, w);
  }

  SPFA(s);

  printf("%d %d\n", d[t].first, -d[t].second);



  return 0;
}
