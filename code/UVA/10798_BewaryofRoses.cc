/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 23 May 2016 14:49:32
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

int n;

struct heapNode
{
  int x, y, d, rose[4];
  heapNode() {}
  heapNode(int x,int  y, int r0, int r1, int r2, int r3)
  {
    this->x = x;
    this->y = y;
    rose[0] = r0;
    rose[1] = r1;
    rose[2] = r2;
    rose[3] = r3;
    d = std::max(std::max(r0, r1), std::max(r2, r3));
  }
  void modify()
  {
    d = *std::max_element(rose, rose + 4);
  }
  bool operator < (const heapNode &rhs) const
  {
    return d > rhs.d;
  }
};

bool vis[21][21][11][11][11][11];
char g[22][22];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool onedge(int x, int y)
{
  return 0 == x || x == n - 1 || 0 == y || y == n - 1;
}

int bfs(int sx, int sy)
{
  memset(vis, false, sizeof vis);
  std::priority_queue<heapNode> q;
  vis[sx][sy][0][0][0][0] = true;
  q.push(heapNode(sx, sy, 0, 0, 0, 0));

  while (!q.empty())
  {
    heapNode current = q.top(); q.pop();
    if (onedge(current.x, current.y)) return current.d;


    for (int i = 0; i < 4; i++)
    {
      heapNode next = current;
      next.x += dx[i];
      next.y += dy[i];

      if (g[next.x][next.y] == 'R') next.rose[0]++;
      if (g[n - 1 - next.y][next.x] == 'R') next.rose[1]++;
      if (g[next.y][n - 1 - next.x] == 'R') next.rose[2]++;
      if (g[n - 1 - next.x][n - 1 - next.y] == 'R') next.rose[3]++;

      next.modify();

      if (vis[next.x][next.y][next.rose[0]][next.rose[1]][next.rose[2]][next.rose[3]]) continue;
      vis[next.x][next.y][next.rose[0]][next.rose[1]][next.rose[2]][next.rose[3]] = true;
      q.push(next);
    }
  }

  return 0;
}

inline void find(int &x, int &y)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (g[i][j] == 'P')
      {
        x = i;
        y = j;
        return ;
      }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  while (scanf("%d", &n) == 1 && n != 0)
  {
    for (int i = 0; i < n; i++) scanf("%s", g[i]);

    int x = 0, y = 0;
    find(x, y);

    printf("At most %d rose(s) trampled.\n", bfs(x, y));
  }




  return 0;
}
