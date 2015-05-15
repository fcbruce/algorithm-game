/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 15 May 2015 10:17:23 AM CST
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

char G[maxn][maxn];
double vis[maxn][maxn];
int n,m;

struct node
{
  int x,y;
  double d;
  double f;
  bool operator < (const node &rhs) const
  {
    return d+f>rhs.d+rhs.f;
  }
};

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

char buff[233];

inline int dcmp(double lhs,double rhs)
{
  if (fabs(lhs-rhs)<eps) return 0;
  return lhs<rhs?-1:1;
}

inline double man(int sx,int sy,int tx,int ty,double p)
{
  return abs(sx-tx)*p+abs(ty-sy);
}

double bfs(int sx,int sy,int tx,int ty,double p)
{
  priority_queue<node> q;
  q.push((node){sx,sy,0,man(sx,sy,tx,ty,p)});
  memset(vis,0x7f,sizeof vis);
  vis[sx][sy]=0;

  while (!q.empty())
  {
    node c=q.top();q.pop();

    if (c.x==tx && c.y==ty) return c.d;

    for (int i=0;i<4;i++) 
    {
      double d=p;
      if (i<2) d=1;

      int nx=c.x+dx[i];
      int ny=c.y+dy[i];
      double nd=c.d+d;

      if (nx>0 && nx<=n && ny>0 && ny<=m && G[nx][ny]==' ' && dcmp(vis[nx][ny],nd)>0)
      {
        vis[nx][ny]=nd;
        q.push((node){nx,ny,nd,nd+man(nx,ny,tx,ty,p)});
      }
    }
  }

  return 1e8;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    double k;
    scanf("%lf %d",&k,&n);
    fgets(buff,107,stdin);

    int sx,sy,tx,ty;
    for (int i=1;i<=n;i++)
    {
      int j=1;
      gets(G[i]+1);
      m=strlen(G[i]+1);
      for (int j=1;j<=m;j++)
      {
        if (G[i][j]=='S')
        {
          sx=i;
          sy=j;
          G[i][j]=' ';
        }
        if (G[i][j]=='E')
        {
          tx=i;
          ty=j;
          G[i][j]=' ';
        }
      }
    }

    double l=0,r=10;
    double res;
    while (dcmp(l,r)<0) 
    {
      double mid=(l+r)/2.0;

      if (dcmp(bfs(sx,sy,tx,ty,mid),k)<=0)
        l=mid;
      else 
        res=r=mid;
    }

    printf("Case #%d: %.3f%%\n",++__,res*100);
  }



  return 0;
}
