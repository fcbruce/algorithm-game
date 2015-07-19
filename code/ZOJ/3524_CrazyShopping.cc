/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 19 Jul 2015 09:06:40 AM CST
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

#define maxm 60007
#define maxn 607

using namespace std;

int dp[maxn][2007];
int cost[maxn][2007];
int w[maxn],val[maxn];
int fir[maxn];
int u[maxm],v[maxm],len[maxm],nex[maxm];
int e_max;
int q[maxm<<3];
int inq[maxn];
int W;

void add_edge(int s, int t, int w)
{
  int e=e_max++;
  u[e]=s;v[e]=t;len[e]=w;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
  int f, r;
  memset(inq, 0, sizeof inq);
  memset(cost, 0x3f, sizeof cost);
  memset(cost[s], 0, sizeof cost[s]);
  memset(dp, 0, sizeof dp);
  for (int i = w[s]; i <= W; i++) 
    dp[s][i] = max(dp[s][i], dp[s][i-w[s]] + val[s]);
  q[f = r = 0] = s;

  while (f <= r)
  {
    int x = q[f++];
    inq[x] = false;
    for (int e = fir[x]; ~e; e = nex[e])
    {
      bool update = false;
      for (int i = 0; i <= W; i++)
      {
        if (dp[x][i] > dp[v[e]][i])
        {
          update = true;
          dp[v[e]][i] = dp[x][i];
          cost[v[e]][i] = cost[x][i] + i * len[e];
        }
        else if (dp[x][i] == dp[v[e]][i])
        {
          if (cost[v[e]][i] > cost[x][i] + i * len[e])
          {
            update = true;
            cost[v[e]][i] = cost[x][i] + i * len[e];
          }
        }
      }
      
      for (int i = w[v[e]]; i <= W; i++)
      {
        if (dp[v[e]][i] < dp[v[e]][i-w[v[e]]] + val[v[e]])
        {
          update = true;
          dp[v[e]][i] = dp[v[e]][i-w[v[e]]] + val[v[e]];
          cost[v[e]][i] = cost[v[e]][i-w[v[e]]];
        }
        else if (dp[v[e]][i] == dp[v[e]][i-w[v[e]]] + val[v[e]] &&
            cost[v[e]][i] > cost[v[e]][i-w[v[e]]])
        {
          update = true;
          cost[v[e]][i] = cost[v[e]][i-w[v[e]]];
        }
      }

      if (update && !inq[v[e]])
      {
        inq[v[e]] = true;
        q[++r] = v[e];
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,s;

  while (scanf("%d %d %d %d", &n, &m, &W, &s) == 4)
  {
    for (int i = 1; i <= n; i++) scanf("%d %d", w + i, val + i);

    memset(fir, -1, sizeof fir);
    e_max = 0;

    while (m--)
    {
      int u,v,w;
      scanf("%d %d %d", &u, &v, &w);
      add_edge(u, v, w);
    }

    SPFA(s);

    int maxv = 0, minc = INF;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= W; j++)
      {
        if (dp[i][j] > maxv)
        {
          maxv = dp[i][j];
          minc = cost[i][j];
        }
        else if(dp[i][j] == maxv)
        {
          minc = min(minc, cost[i][j]);
        }
      }
    }

    printf("%d\n",minc);

  }



  return 0;
}
