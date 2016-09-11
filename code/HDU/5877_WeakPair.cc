/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 10 Sep 2016 13:34:10
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
int n; LL k;

LL sum[maxn << 2];
LL X[maxn];
int val[maxn];
int xn;
bool mayberoot[maxn];

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

LL res;

LL query(int a, int b, int k, int l, int r)
{
  if (b <= l || r <= a) return 0;
  if (a <= l && r <= b) return sum[k];

  return query(a, b, k * 2 + 1, l, l + r >> 1) + query(a, b, k * 2 + 2, l + r >> 1, r);
}

void update(int p, int v, int k, int l, int r)
{
  if (l + 1 == r)
  {
    sum[k] += v;
    return ;
  }

  int m = l + r >> 1;
  if (p < m) update(p, v, k * 2 + 1, l, m);
  else update(p, v, k * 2 + 2, m, r);
  
  sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
}

void dfs(int s)
{
  LL r = k / val[s];
  int y = std::upper_bound(X, X + xn, r) - X;

  LL cnt = query(0, y, 0, 0, xn);
  res += cnt;

  int x = std::lower_bound(X, X + xn, val[s]) - X;
  update(x, 1, 0, 0, xn);

  for (int e = fir[s]; ~e; e = nex[e])
  {
    dfs(v[e]);
  }

  update(x, -1, 0, 0, xn);
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
    scanf("%d"lld, &n, &k);

    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 0; i < n; i++)
    {
      scanf("%d", val + 1 + i);
      X[i] = val[i + 1];
    }

    X[n] = INF;
    xn = n + 1;
    std::sort(X, X + xn);
    xn = std::unique(X, X + xn) - X;
    
    memset(mayberoot, true, sizeof mayberoot);

    for (int i = 1; i < n; i++) 
    {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
      mayberoot[v] = false;
    }

    int root = 1; for (; !mayberoot[root]; root++) ;

    memset(sum, 0, sizeof sum);

    res = 0;
    dfs(root);
    printf(lld"\n", res);
  }




  return 0;
}
