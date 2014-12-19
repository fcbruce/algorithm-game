/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-20 23:52:56 
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

struct _point
{
  int x,y;
};
vector<_point> p;

map<pair<int,int>,bool> MAP;

int G[64][64];

int n,m;
int MIN;

inline bool
check(int x,int y)
{
  return 0<=x && x<n && 0<=y && y<m;
}

bool
judge(int x,int y,int dx,int dy)
{
  int cnt=1;
  
  int px=x+dx,py=y+dy;
  while (check(px,py))
  {
    if (G[px][py]==0) return false;
    px+=dx;py+=dy;
    cnt++;
  }
  
  px=x-dx;py=y-dy;
  while (check(px,py))
  {
    if (G[px][py]==0) return false;
    px-=dx;py-=dy;
    cnt++;
  }

  return cnt>=3;
}

int
remove(int x,int y,int dx,int dy)
{
  int cnt=1;
  G[x][y]--;
  
  int px=x+dx,py=y+dy;
  while (check(px,py))
  {
    G[px][py]--;
    px+=dx;py+=dy;
    cnt++;
  }
  
  px=x-dx;py=y-dy;
  while (check(px,py))
  {
    G[px][py]--;
    px-=dx;py-=dy;
    cnt++;
  }
  
  return cnt;
}

void
resume(int x,int y,int dx,int dy)
{
  G[x][y]++;
  
  int px=x+dx,py=y+dy;
  while (check(px,py))
  {
    G[px][py]++;
    px+=dx;py+=dy;
  }
  
  px=x-dx;py=y-dy;
  while (check(px,py))
  {
    G[px][py]++;
    px-=dx;py-=dy;
  }
}


void
dfs(int res,int rest)
{
  if (rest==0)
  {
    MIN=min(MIN,res);
    return ;
  }
  if (res>=MIN) return ;
  
  for (int i=0;i<p.size();i++)
  {
    int x=p[i].x,y=p[i].y;
    if (G[x][y]==0) continue;
    MAP.clear();
    
    for (int j=i+1;j<p.size();j++)
    {
      int px=p[j].x,py=p[j].y;
      if (G[px][py]==0) continue;
      
      int dx=px-x,dy=py-y;
      int gcd=__gcd(dx,dy);
      dx/=gcd;dy/=gcd;
      if (MAP[make_pair(dx,dy)]) continue;
      MAP[make_pair(dx,dy)]=true;
      dx*=gcd;dy*=gcd;
      
      if (judge(x,y,dx,dy))
      {
        int k=remove(x,y,dx,dy);
        
        dfs(res+1,rest-k);
        
        resume(x,y,dx,dy);
      }
      
    }
    
    return ;
  }
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    scanf("%d%d",&n,&m);
    n++;m++;
    
    int cnt=0;
    p.clear();
    
    for (int i=0;i<n;i++)
    {
      for (int j=0;j<m;j++)
      {
        scanf("%d",&G[i][j]);
        if (G[i][j])
        {
          p.push_back((_point){i,j});
          cnt+=G[i][j];
        }
      }
    }
    
    MIN=min(14,cnt/3);
    
    dfs(0,cnt);
    
    printf("%d\n",MIN);
  }
  
  return 0;
}



