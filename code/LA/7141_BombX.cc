/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 06 Oct 2015 09:58:51 AM CST
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

const int maxn = 400007;
const int maxm = 0;

std::pair<int, int> pawns[maxn];

struct line
{
  int x, y, h, v;
  bool operator < (const line &rhs) const
  {
    if (h == rhs.h) return v > rhs.v;
    return h < rhs.h;
  }
};

std::vector<line> lines;

int max[maxn << 2], boom[maxn << 2], cover[maxn << 2];
int bonus_x[maxn], bonus_y[maxn];
int sumx[maxn], sumy[maxn];
int boomx[maxn], boomy[maxn];

int X[maxn], Y[maxn];
int XN, YN;


inline void addx(int x, int w)
{
  X[XN++] = x - 1;
  X[XN++] = x;
  X[XN++] = x + w;
  X[XN++] = x + w + 1;
}

inline void addy(int y, int h)
{
  Y[YN++] = y - 1;
  Y[YN++] = y;
  Y[YN++] = y + h;
  Y[YN++] = y + h + 1;
}

void build(int k, int l, int r)
{
  cover[k] = 0;
  if (l + 1 == r)
  {
    max[k] = boom[k] = boomx[l];
    return ;
  }

  build(k * 2 + 1, l, l + r >> 1);
  build(k * 2 + 2, l + r >> 1, r);

  max[k] = std::max(max[k * 2 + 1], max[k * 2 + 2]);
  boom[k] = std::max(boom[k * 2 + 1], boom[k * 2 + 2]);
}

void update(int a, int b, int v, int k, int l, int r)
{
  if (b <= l || r <= a) return ;
  if (a <= l && r <= b)
  {
    cover[k] += v;
    if (cover[k] != 0) max[k] = 0;
    else
    {
      if (l + 1 == r) max[k] = boom[k];
      else max[k] = std::max(max[k * 2 + 1], max[k * 2 + 2]);
    }
    return ;
  }

  update(a, b, v, k * 2 + 1, l, l + r >> 1);
  update(a, b, v, k * 2 + 2, l + r >> 1, r);

  if (cover[k] != 0) max[k] = 0;
  else max[k] = std::max(max[k * 2 + 1], max[k * 2 + 2]);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);

    lines.clear();
    XN = 0;
    YN = 0;

    for (int i = 0, x, y; i < n; i++)
    {
      scanf("%d%d", &x, &y);
      addx(x, w);
      addy(y, h);
      lines.push_back({x, x + w, y, 1});
      lines.push_back({x, x + w, y + h, -1});
      pawns[i] = {x, y};
    }

    std::sort(X, X + XN);
    XN = std::unique(X, X + XN) - X;
    std::sort(Y, Y + YN);
    YN = std::unique(Y, Y + YN) - Y;

    std::sort(lines.begin(), lines.end());

    memset(bonus_x, 0, sizeof bonus_x);
    memset(bonus_y, 0, sizeof bonus_y);

    for (int i = 0; i < n; i++)
    {
      int x = std::lower_bound(X, X + XN, pawns[i].first) - X;
      int y = std::lower_bound(Y, Y + YN, pawns[i].second) - Y;

      bonus_x[x]++;
      bonus_y[y]++;
    }

    sumx[0] = sumy[0] = 0;

    for (int i = 1; i < XN; i++) sumx[i] = sumx[i - 1] + bonus_x[i];
    for (int i = 1; i < YN; i++) sumy[i] = sumy[i - 1] + bonus_y[i];

    boomx[0] = boomy[0] = 0;
    for (int i = 1, j = 1; i < XN; i++)
    {
      while (j < XN && X[j] + w <= X[i]) j++;
      boomx[i] = sumx[i] - sumx[j - 1];
    }
    for (int i = 1, j = 1; i < YN; i++)
    {
      while (j < YN && Y[j] + h <= Y[i]) j++;
      boomy[i] = sumy[i] - sumy[j - 1];
    }

    int res = 0;

    build(0, 0, XN);

    for (size_t i = 0, j = 0; i < YN; i++)
    {
      while (j < lines.size() && lines[j].h <= Y[i])
      {
        int a = std::lower_bound(X, X + XN, lines[j].x) - X;
        int b = std::lower_bound(X, X + XN, lines[j].y) - X;

        update(a, b, lines[j].v, 0, 0, XN);
        j++;
      }

      res = std::max(res, boomy[i] + max[0]);
    }

    printf("Case #%d: %d\n", ++__, res);
  }




  return 0;
}
