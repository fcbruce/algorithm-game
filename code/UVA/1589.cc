/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 11 Feb 2015 04:45:11 PM CST
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
#define maxn 10

using namespace std;

int n;

struct Mate
{
  char type;
  int x,y;
  void read()
  {
    scanf(" %c %d %d",&type,&x,&y);
  }
}mate[maxn];

int cnt_y(int x,int y,int i)
{
  int res=0;
  for (int j=0;j<n;j++) if (i!=j && mate[j].y==y && x<mate[j].x && mate[j].x<mate[i].x) res++;
  return res;
}

int cnt_x(int x,int y,int i)
{
  int res=0;
  for (int j=0;j<n;j++) if (i!=j && mate[j].x==x && y<mate[j].y && mate[j].y<mate[i].y) res++;
  return res;
}

bool Null(int x,int y)
{
  for (int i=0;i<n;i++) if (mate[i].x==x && mate[i].y==y) return false;
  return true;
}

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
int kx[]={-2,-2,-1,1,2,2,1,-1};
int ky[]={-1,1,2,2,1,-1,-2,-2};
int fx[]={-1,-1,0,0,1,1,0,0};
int fy[]={0,0,1,1,0,0,-1,-1};

bool live(int x,int y)
{
  if (!(0<x && x<4 && 3<y && y<7)) return false;
  
  for (int i=0;i<n;i++)
  {
    if (mate[i].type=='G') 
    {
      if (mate[i].y!=y) continue;
      if (cnt_y(x,y,i)==0)return false;
    }
    else if (mate[i].type=='R')
    {
      if (mate[i].x==x && mate[i].y==y) continue;
      if (mate[i].x==x && cnt_x(x,y,i)==0) return false;
      if (mate[i].y==y && cnt_y(x,y,i)==0) return false;
    }
    else if (mate[i].type=='H')
    {
      int sx=mate[i].x,sy=mate[i].y;
      for (int j=0;j<8;j++) if (sx+kx[j]==x && sy+ky[j]==y)
      {
        if (Null(sx+fx[j],sy+fy[j])) return false;
      }
    }
    else 
    {
      if (mate[i].x==x && cnt_x(x,y,i)==1) return false;
      if (mate[i].y==y && cnt_y(x,y,i)==1) return false;
    }
  }

  return true;
}

inline bool dead(int x,int y)
{
  for (int i=0;i<4;i++) if (live(x+dx[i],y+dy[i])) return false;
  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int gx,gy;

  while (scanf("%d%d%d",&n,&gx,&gy),n||gx||gy)
  {
    for (int i=0;i<n;i++) mate[i].read();

    puts(dead(gx,gy)?"YES":"NO");
  }


  return 0;
}
