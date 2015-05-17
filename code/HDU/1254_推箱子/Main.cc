/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 01:34:06 PM CST
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

#define maxm 100
#define maxn 10

using namespace std;

int n,m;
int G[maxn][maxn];
bool vis[maxn][maxn][4],go[maxn][maxn];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct node
{
  int x,y,px,py,d;
}q[maxm<<4];

inline bool ok(int x,int y)
{
  return 0<=x && x<n && 0<=y && y<m && G[x][y]==0;
}

bool dfs(int sx,int sy,int tx,int ty)
{
  if (sx==tx && sy==ty) return true;
  go[sx][sy]=true;
  for (int i=0;i<4;i++)
  {
    int x=sx+dx[i];
    int y=sy+dy[i];
    if (ok(x,y) && !go[x][y] && dfs(x,y,tx,ty)) return true;
  }
  return false;
}

int sx,sy,px,py,tx,ty;

int bfs()
{
  int f,r;
  memset(vis,0,sizeof vis);

  node s=(node){sx,sy,px,py,0};
  memset(vis[sx][sy],true,sizeof vis[sx][sy]);
  q[f=r=0]=s;

  while (f<=r)
  {
    node c=q[f++];
    if (c.x==tx && c.y==ty) return c.d;

    for (int i=0;i<4;i++)
    {
      int px=c.x-dx[i];
      int py=c.y-dy[i];
      int tx=c.x+dx[i];
      int ty=c.y+dy[i];

      G[c.x][c.y]=1;

      if (ok(tx,ty) && !vis[tx][ty][i] && ok(px,py))
      {
        memset(go,0,sizeof go);
        if (dfs(c.px,c.py,px,py))
        {
          q[++r]=(node){tx,ty,px,py,c.d+1};
          vis[tx][ty][i]=true;
        }
      }

      G[c.x][c.y]=0;
    }
  }

  return -1;
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
    scanf("%d%d",&n,&m);

    for (int i=0;i<n;i++) for (int j=0;j<m;j++)
    {
      scanf("%d",G[i]+j);
      if (G[i][j]==2) 
      {
        sx=i;sy=j;
        G[i][j]=0;
      }
      else if (G[i][j]==3)
      {
        tx=i;ty=j;
        G[i][j]=0;
      }
      else if (G[i][j]==4)
      {
        px=i;py=j;
        G[i][j]=0;
      }
    }

    printf("%d\n",bfs());
  }



  return 0;
}
