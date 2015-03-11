/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 06:28:28 PM CST
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
#define maxn 107

using namespace std;

bool G[maxn][maxn];

int com[maxn][maxn];

struct node
{
  int x,y;
}q[1000007];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    memset(G,0,sizeof G);
    memset(com,0,sizeof com);

    for (int i=0;i<m;i++) 
    {
      int u,v;
      scanf("%d%d",&u,&v);
      if (G[u][v]) continue;
      G[u][v]=G[v][u]=true;
    }


    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) 
    {
      for (int k=0;k<n;k++) if (k!=i && k!=j) if (G[i][k] && G[j][k])
      {
        com[i][j]++;
      }
    }

    int f=0,r=-1;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++)
    {
      if (com[i][j]>=k && !G[i][j])
      {
        q[++r]={i,j};
      }
    }

    int res=0;

    while (f<=r)
    {
      node c=q[f++];
      if (G[c.x][c.y]) continue;
      if (c.x==c.y) continue;
      G[c.x][c.y]=G[c.y][c.x]=true;
      res++;

      int u=c.x,v=c.y;
      for (int i=0;i<n;i++)
      {
        if (G[u][i])
        {
          com[i][v]++;
          if (com[i][v]>=k && !G[i][v])
          {
            q[++r]={i,v};
          }
          com[v][i]++;
          if (com[v][i]>=k && !G[v][i])
          {
            q[++r]={v,i};
          }
        }

        if (G[i][v])
        {
          com[i][u]++;
          if (com[i][u]>=k && !G[i][u])
          {
            q[++r]={i,u};
          }
          com[u][i]++;
          if (com[u][i]>=k && !G[u][i])
          {
            q[++r]={u,i};
          }
        }
      }
    }

    printf("%d\n",res);
  }



  return 0;
}
