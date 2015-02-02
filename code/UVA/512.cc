/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 30 Jan 2015 05:00:53 PM CST
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
#define maxn 23333

using namespace std;

struct __cmd
{
  int type;
  int x1,y1,x2,y2;
  int a,x[10];

  void ex()
  {
    type=0;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  }
  void dirc(int t)
  {
    type=t;
    scanf("%d",&a);
    for (int i=0;i<a;i++) scanf("%d",x+i);
  }
}cmd[maxn];
int q;

bool did(int &x,int &y)
{
  for (itn i=0;i<q;i++)
  {
    itn dx=0,dy=0;
    switch (cmd[i].type)
    {
      case 1:
        for (int j=0;j<cmd[i].a;++j)
          if (cmd[i].x[j]==x) return false;
          else if (cmd[i].x[j]<x) dx--;
        break;
      case 2:
        for (int j=0;j<cmd[i].a;++j)
          if (cmd[i].x[j]==y) return false;
          else if (cmd[i].x[j]<y) dy--;
        break;
      case 3:
        for (int j=0;j<cmd[i].a;++j)
          if (cmd[i].x[j]<=x) dx++;
        break;
      case 4:
        for (int j=0;j<cmd[i].a;++j)
          if (cmd[i].x[j]<=y) dy++;
        break;
      default :
        if (cmd[i].x1==x && cmd[i].y1==y) 
        {
          x=cmd[i].x2;
          y=cmd[i].y2;
        }
        else if (cmd[i].x2==x && cmd[i].y2==y) 
        {
          x=cmd[i].x1;
          y=cmd[i].y1;
        }
    }
    x+=dx;y+=dy;
  }
  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  int n,m;

  char op[5];

  while (scanf("%d%d",&n,&m),n!=0 && m!=0)
  {
    scanf("%d",&q);
    for (int i=0;i<q;i++)
    {
      scanf("%s",op);
      
      if (strcmp(op,"EX")==0)
        cmd[i].ex();
      else if (strcmp(op,"DR")==0)
        cmd[i].dirc(1);
      else if (strcmp(op,"DC")==0)
        cmd[i].dirc(2);
      else if (strcmp(op,"IR")==0)
        cmd[i].dirc(3);
      else if (strcmp(op,"IC")==0)
        cmd[i].dirc(4);
    }

    if (__>0) putchar('\n');
    printf("Spreadsheet #%d\n",++__) ;
    
    int qs;
    scanf("%d",&qs);
    while (qs--)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      printf("Cell data in (%d,%d) ",x,y);
      if (did(x,y)) printf("moved to (%d,%d)\n",x,y);
      else puts("GONE");
    }
  }

  return 0;
}
