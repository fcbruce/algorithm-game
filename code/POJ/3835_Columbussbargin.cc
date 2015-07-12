/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 05 Jul 2015 09:54:09 AM CST
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

#define maxm 27
#define maxn 27

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int q[maxm<<3];
int d[maxn];
bool inq[maxn];

bool vis[100];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int n)
{
  int f=0,r=-1;
  memset(inq,true,sizeof inq);
  for (int i=1;i<=n;i++) q[++r]=i;

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (d[v[e]]>d[u[e]]+w[e])
      {
        d[v[e]]=d[u[e]]+w[e];
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    memset(d,0,sizeof d);
    memset(vis,0,sizeof vis);
    int n;
    scanf("%d",&n);

    for (int i=0,q,p;i<n;i++)
    {
      scanf("%d%d",&q,&p);
      d[q]=p-1;
    }

    for (int i=1;i<=n;i++) for (int j=1;j<i;j++) if (d[i]==d[j])
    {
      add_edge(i,j,0);
      add_edge(j,i,0);
    }


    int m;
    scanf("%d",&m);

    for (int i=0,u,v,w;i<m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      add_edge(u,v,w);
    }
    
    SPFA(n);

    for (int i=0;i<n;i++)
      printf("%d %d\n",i+1,d[i+1]);

    int cnt=0;

    for (int k=1;k<=n;k++)
    {
      for (int i=1;i<=n;i++) for (int j=1;j<i;j++) if (k!=i && k!=j && d[k]==d[i]+d[j])
      {
        cnt++;
        goto FOUND;
      }
FOUND:;
    }
    
    printf("%d\n",cnt);
  }



  return 0;
}
