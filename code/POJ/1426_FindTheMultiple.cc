/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 26 Jan 2016 01:22:51 AM PST
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

const int maxn = 0;
const int maxm = 0;

bool vis[2][202];

struct info
{
  int pre, v, remainder;
}q[404];

void print(int p)
{
  if (p == -1) return ;
  print(q[p].pre);
  printf("%d", q[p].v);
}

void bfs(int n)
{
  int f, r;
  memset(vis, false, sizeof vis);
  q[f = r = 0] = {-1, 1, 1 % n};
  vis[1][1 % n] = true;

  while (f <= r)
  {
    info cur = q[f++];
    if (cur.remainder == 0)
    {
      print(f - 1);
      puts("");
      return ;
    }

    for (int i = 0; i < 2; i++)
    {
      info tmp = {f - 1, i, (cur.remainder * 10 + i) % n};
      if (vis[i][tmp.remainder]) continue;
      vis[i][tmp.remainder] = true;
      q[++r] = tmp;
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d", &n), n != 0)
  {
    bfs(n);
  }




  return 0;
}
