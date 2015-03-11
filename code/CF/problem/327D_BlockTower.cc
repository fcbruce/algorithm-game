/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 07:12:25 PM CST
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
#define maxn 507 

using namespace std;

char g[maxn][maxn];

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

struct rr
{
  char c;
  int x,y;
  void pr()
  {
    printf("%c %d %d\n",c,x,y);
  }
};

vector<rr> res;
vector<pair<int,int> > vp;

pair<int,int> q[555555];
int f,r;

void bfs(int sx,int sy)
{
  q[f=r=0]={sx,sy};
  g[sx][sy]='R';
  vp.clear();

  while (f<=r)
  {
    auto x=q[f++];

    for (int i=0;i<4;i++)
    {
      int tx=x.first+dx[i];
      int ty=x.second+dy[i];
      if (g[tx][ty]=='B') 
      {
        g[tx][ty]='R';
        q[++r]={tx,ty};
        vp.push_back({tx,ty});
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  itn n,m;
  scanf("%d%d",&n,&m);
  
  memset(g,'#',sizeof g);

  for (int i=1;i<=n;i++) 
    scanf("%s",g[i]+1);

  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (g[i][j]=='.')
  {
    g[i][j]='B';
    res.push_back({'B',i,j});
  }


  for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (g[i][j]=='B')
  {
    bfs(i,j);
    reverse(vp.begin(),vp.end());
    for (auto &e : vp) 
    {
      res.push_back({'D',e.first,e.second});
      res.push_back({'R',e.first,e.second});
    }
    
  }

  printf("%d\n",(int)res.size());
  for (auto &e : res) e.pr();

  return 0;
}
