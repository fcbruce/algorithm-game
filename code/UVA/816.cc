/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 02 Mar 2015 03:59:12 PM CST
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

#define maxm 23333
#define maxn 11

using namespace std;

char des[23];

char __dir[]="NESW";

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

vector<int> go[maxn][maxn][4];

bool G[maxn][maxn];
bool vis[maxn][maxn][4];

int sx,sy,tx,ty;
int sd,td;

char buff[233];

struct node
{
  int x,y,d;
}q[maxm];

node pre[maxn][maxn][4];

vector<pair<int,int> > res;

void line(int x,int y,int d)
{
  auto cur=pre[x][y][d];
  if (x!=-1 || y!=-1 || d!=-1) line(cur.x,cur.y,cur.d);
  else 
  {
    res.push_back({sx,sy});
    return;
  }
  res.push_back({x,y});
}

inline void analyse(itn x,int y,char *s)
{
  int pos=[&](char ch)
  {
    for (itn i=0;i<4;i++) if (ch==__dir[i]) return i;
  }(s[0]);

  for (int i=1;s[i]!='\0';i++)
  {
    int nex=pos;
    if (s[i]=='R') nex=(pos+1)%4;
    if (s[i]=='L') nex=(pos+3)%4;
    go[x][y][pos].push_back(nex);
  }
}

bool bfs()
{
  int f,r;
  q[f=r=0]={sx+dx[sd],sy+dy[sd],sd};

  memset(vis,0,sizeof vis);
  vis[sx+dx[sd]][sy+dy[sd]][sd]=true;
  pre[sx+dx[sd]][sy+dy[sd]][sd]={-1,-1,-1};

  while (f<=r)
  {
    auto cur=q[f++];
    int x=cur.x,y=cur.y,d=cur.d;
    td=d;
    if (x==tx && y==ty) return true;

    for (auto td : go[x][y][d])
    {
      int tx=x+dx[td],ty=y+dy[td];
      if (G[tx][ty] && !vis[tx][ty][td])
      {
        vis[tx][ty][td]=true;
        pre[tx][ty][td]={x,y,d};
        q[++r]={tx,ty,td};
      }
    }
  }

  return false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%[^\n]",des),strcmp(des,"END")!=0)
  {
    printf("%s",des);
    char ch;
    scanf("%d %d %c %d %d",&sx,&sy,&ch,&tx,&ty);
    sd=[&](char ch)
    {
      for (itn i=0;i<4;i++) if (ch==__dir[i]) return i;
    }(ch);

    memset(G,0,sizeof G);
    G[tx][ty]=true;
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) for (int k=0;k<4;k++) go[i][j][k].clear();

    {
      int x,y;
      while (scanf("%d",&x),x!=0)
      {
        scanf("%d",&y);
        G[x][y]=true;
        while (scanf("%s",buff),buff[0]!='*')
          analyse(x,y,buff);
      }
      getchar();
    }

    if (!bfs())
    {
      puts("\n  No Solution Possible");
      continue;
    }

    res.clear();
    line(tx,ty,td);

    int cnt=0;
    for (auto &e : res)
    {
      if (cnt%10==0) printf("\n ");
      printf(" (%d,%d)",e.first,e.second);
      cnt++;
    }
    puts("");
  }

  return 0;
}
