/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 16 Aug 2015 10:00:21 AM CST
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

#define maxm 20007
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm], v[maxm], w[maxm], nex[maxm];
int e_max;

int n, k;

int size[maxn], balance[maxn];
bool vis[maxn];

inline void add_edge(int s, int t, int c)
{
  int e = e_max++;
  u[e] = s; v[e] = t; w[e] = c;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void dfs_root(int s, int f, int &root, int n)
{
  size[s] = 1;
  balance[s] = 0;
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != f && !vis[v[e]])
  {
    dfs_root(v[e], s, root, n);
    size[s] += size[v[e]];
    balance[s] = max(balance[s], size[v[e]]);
  }
  balance[s] = max(balance[s], n - size[s]);
  if (root == -1 || balance[root] > balance[s]) root = s;
}

void dfs_len(int s, int f, int d, vector<int> &tmp)
{
  tmp.push_back(d);
  for (int e = fir[s]; ~e; e = nex[e]) if (v[e] != f && !vis[v[e]])
    dfs_len(v[e], s, d + w[e], tmp);
}

int calc(vector<int> &tmp)
{
  sort(tmp.begin(),tmp.end());
  int res = 0;
  for (int i = 0, j = tmp.size() - 1; i < j;)
  {
    if (tmp[i] + tmp[j] <= k)
    {
      res += j - i;
      i++;
    }
    else j--;
  }
  return res;
}

int solve(int s,int n)
{
  int root = -1;
  dfs_root(s, -1, root, n);
  vector<int> total;
  total.push_back(0);
  int res = 0;
  vis[root] = true;
  for (int e = fir[root]; ~e; e = nex[e]) if (!vis[v[e]])
  {
    vector<int> tmp;
    dfs_len(v[e], root, w[e], tmp);
    res -= calc(tmp);
    for (size_t i = 0; i < tmp.size(); i++) total.push_back(tmp[i]);
    res += solve(v[e], size[v[e]]);
  }
  return res += calc(total);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d", &n, &k) == 2 && (n !=0 || k != 0))
  {
    e_max = 0;
    memset(fir, -1, sizeof fir);

    for (int i = 1, u, v ,w; i < n; i++)
    {
      scanf("%d%d%d", &u, &v, &w);
      add_edge(u, v, w);
      add_edge(v, u, w);
    }

    memset(vis, false, sizeof vis);

    printf("%d\n", solve(1,n));
  }



  return 0;
}
