/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 17 Jul 2015 07:58:44 PM CST
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

#define maxm 
#define maxn 1007

using namespace std;

struct point
{
  int b, w, h, s;
  void read()
  {
    scanf("%d %d %d %d", &b, &w, &h, &s);
    w += 1000;
    h += 1000;
  }
  bool operator < (const point &rhs) const
  {
    return b < rhs.b;
  }
}point[maxn];

struct segment
{
  int a, b, y, v;
  bool operator < (const segment &rhs) const
  {
    if (y == rhs.y) return v < rhs.v;
    return y < rhs.y;
  }
}seg[maxn << 1];

int B[maxn << 1];

int addv[maxn << 5], minv[maxn << 5];

inline void pushdown(int k)
{
  int lc = k * 2 + 1;
  int rc = k * 2 + 2;
  addv[lc] += addv[k];
  addv[rc] += addv[k];
  minv[lc] += addv[k];
  minv[rc] += addv[k];
  addv[k] = 0;
}

inline void pushup(int k)
{
  minv[k] = min(minv[k * 2 + 1], minv[k * 2 + 2]);
}

void update(int a, int b, int v, int k, int l, int r)
{
  if (b <= l || r <= a) return ;
  if (a <= l && r <= b) 
  {
    addv[k] += v;
    minv[k] += v;
    return ;
  }

  pushdown(k);
  update(a, b, v, k * 2 + 1, l, l + r >> 1);
  update(a, b, v, k * 2 + 2, l + r >> 1, r);
  pushup(k);
}

int scan(segment seg[], int n)
{
  memset(addv, 0, sizeof addv);
  memset(minv, 0, sizeof minv);

  int res = 0;

  for (int i = 0; i < n; i++)
  {
    update(seg[i].a, seg[i].b, seg[i].v, 0, 0, 4007);
    res = min(res, minv[0]);
  }

  return res;
}

int solve(int n, int b, int w, int h)
{
  int bn = 0;
  for (int i = 0; i < n; i++) B[bn++] = point[i].b;

  sort(B, B + bn);
  bn = unique(B, B + bn) - B;

  int res = 0;

  for (int k = 0; k < bn; k++)
  {
    int cnt = 0;
    for (int i = 0; i < n && point[i].b <= B[k] + b; i++) 
    {
      if (point[i].b >= B[k] && point[i].s < 0)
      {
        seg[cnt++] = {point[i].w, point[i].w + w + 1, point[i].h, point[i].s};
        seg[cnt++] = {point[i].w, point[i].w + w + 1, point[i].h + h, -point[i].s};
      }
    }
    sort(seg, seg + cnt);

    res = min(res, scan(seg, cnt));
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d", &n) == 1)
  {
    for (int i = 0; i < n; i++) point[i].read();

    sort(point, point + n);

    int b, w, h;
    scanf("%d %d %d", &b, &w, &h);

    int res = solve(n, b, w, h);
    if (res < 0) printf("%d\n", res);
    else puts("Error 404, mahou shoujo not found!");
  }



  return 0;
}
