/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 29 Jul 2015 07:36:35 PM CST
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
#define maxn 

using namespace std;

int g[2][6][6];
int vis[6*6*6*6];
char choice[6*6*6*6];

int sx[2],sy[2];

char dir[]="DLRU";
int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};
int barr[]={1,0,2,3};

void readMaze(int cur)
{
  for (int i=0;i<6;i++) for (int j=0;j<6;j++)
  {
    scanf("%d",&g[cur][i][j]);
    if (g[cur][i][j]&(1<<5))
    {
      sx[cur]=i;
      sy[cur]=j;
    }
  }
}

struct status
{
  int x[2],y[2];
}q[6*6*6*6];

inline int encode(status s)
{
  int res=0;
  res+=s.x[0];
  res*=6;
  res+=s.x[1];
  res*=6;
  res+=s.y[0];
  res*=6;
  res+=s.y[1];
  return res;
}

inline void move(int cur,int x,int y,int d,int &tx,int &ty)
{
  if (g[cur][x][y]&(1<<barr[d]))
  {
    tx=x;
    ty=y;
  }
  else
  {
    tx=x+dx[d];
    ty=y+dy[d];
  }
}

inline bool out(int x)
{
  return x<0 || x>5;
}

inline bool ok(int x[],int y[])
{
  if (out(x[0]) || out(x[1]) || out(y[0]) || out(y[1])) return false;
  if ((g[0][x[0]][y[0]]&(1<<4)) == 0) return false;
  if ((g[1][x[1]][y[1]]&(1<<4)) == 0) return false;
  return true;
}

inline bool win(int x[],int y[])
{
  if ((g[0][x[0]][y[0]]&(1<<6)) == 0) return false;
  if ((g[1][x[1]][y[1]]&(1<<6)) == 0) return false;
  return true;
}

void print(int k)
{
  if (vis[k]==-1) return ;
  print(vis[k]);
  putchar(choice[k]);
}

void bfs()
{
  int f,r;
  memset(vis,0x3f,sizeof vis);
  status s={sx[0],sx[1],sy[0],sy[1]};
  int k=encode(s);
  vis[k]=-1;
  q[f=r=0]=s;

  while (f<=r)
  {
    status cur=q[f++];
    if (win(cur.x,cur.y))
    {
      print(encode(cur));
      puts("");
      return ;
    }

    for (int i=0;i<4;i++)
    {
      int tx[2],ty[2];
      move(0,cur.x[0],cur.y[0],i,tx[0],ty[0]);
      move(1,cur.x[1],cur.y[1],i,tx[1],ty[1]);

      if (ok(tx,ty))
      {
        status nex={tx[0],tx[1],ty[0],ty[1]};
        int k=encode(nex);
        if (vis[k]!=INF) continue;
        vis[k]=encode(cur);
        choice[k]=dir[i];
        q[++r]=nex;
      }
    }
  }

  puts("-1");
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,cur=0;
  scanf("%d",&T_T);

  readMaze(cur);
  cur^=1;
  T_T--;

  while (T_T--)
  {
    readMaze(cur);

    bfs();
    cur^=1;
  }



  return 0;
}
