#include <bits/stdc++.h>
#define maxn 233
#define INF 0x3f3f3f3f
using namespace std;

struct _rectangle
{
  int x1,y1,x2,y2;
}rec[64];

long long G[maxn][maxn];

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int x[maxn],y[maxn];

int XN,YN;

inline bool
in_range(int x,int y)
{
  return 0<=x && x<XN && 0<=y && y<YN;
}

void
dfs(int x,int y,long long status)
{
  G[x][y]=0;
  for (int i=0;i<4;i++)
  {
    int tx=x+dx[i],ty=y+dy[i];
    if (in_range(tx,ty) && G[tx][ty]==status) dfs(tx,ty,status);
  }
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n),n)
  {
    int cnt=0;
    int minx=INF,miny=INF,maxx=-1,maxy=-1;
    for (int i=0,x1,y1,x2,y2;i<n;i++)
    {
      scanf("%d%d%d%d",&x1,&y2,&x2,&y1);
      
      minx=min(minx,min(x1,x2));
      maxx=max(maxx,max(x1,x2));
      miny=min(miny,min(y1,y2));
      maxy=max(maxy,max(y1,y2));
      
      rec[i]=(_rectangle){x1,y1,x2,y2};
      x[cnt]=x1;y[cnt]=y1;
      cnt++;
      x[cnt]=x2;y[cnt]=y2;
      cnt++;
    }
    
    minx--;miny--;
    maxx++;maxy++;

    rec[n++]=(_rectangle){minx,miny,maxx,maxy};
    x[cnt]=minx;y[cnt]=miny;
    cnt++;
    x[cnt]=maxx;y[cnt]=maxy;
    cnt++;

    sort(x,x+cnt);sort(y,y+cnt);
    XN=unique(x,x+cnt)-x;
    YN=unique(y,y+cnt)-y;

    memset(G,0,sizeof G);

    for (int k=0,x1,y1,x2,y2;k<n;k++)
    {
      x1=lower_bound(x,x+XN,rec[k].x1)-x;
      y1=lower_bound(y,y+YN,rec[k].y1)-y;
      x2=lower_bound(x,x+XN,rec[k].x2)-x;
      y2=lower_bound(y,y+YN,rec[k].y2)-y;

      for (int i=x1;i<x2;i++)
      {
        for (int j=y1;j<y2;j++)
        {
          G[i][j]|=(1ll<<k);
        }
      }
    }

    int _cnt=0;
    for (int i=0;i<XN;i++)
    {
      for (int j=0;j<YN;j++)
      {
        if (G[i][j]!=0ll)
        {
          dfs(i,j,G[i][j]);
          _cnt++;
        }
      }
    }

    printf("%d\n",_cnt);
  }


  return 0;
}
