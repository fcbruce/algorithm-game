/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-24 19:28:20 
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
#define maxn 707

using namespace std;

struct _point
{
  int x,y;
}point[maxn];

char str[233];

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T;
  scanf("%d",&T_T);getchar();getchar();
  
  while (T_T--)
  {
    int n=0,x,y;
    while (gets(str)!=NULL && str[0]!='\0')
    {
      sscanf(str,"%d %d",&x,&y);
      point[n++]=(_point){x,y};
    }
    
    long long dx,dy,_x,_y;
    int MAX=0;
    for (int i=0;i<n;i++)
    {
      for (int j=i+1;j<n;j++)
      {
        dx=point[i].x-point[j].x;
        dy=point[i].y-point[j].y;
        int cnt=2;
        for (int k=j+1;k<n;k++)
        {
//          if (k==i || k==j) continue;
          _x=point[i].x-point[k].x;
          _y=point[i].y-point[k].y;
          if (_y*dx==_x*dy) cnt++;
        }
        MAX=max(MAX,cnt);
      }
    }
    
    printf("%d\n",MAX);
    if (T_T) putchar('\n');
  }
  
  return 0;
}



