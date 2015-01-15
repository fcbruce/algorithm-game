/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 10:54:51 AM CST
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

char G[15][15];

int id[15][15];

void print(int x,int y,int dx,int dy)
{
  if (G[x][y]=='*' || G[x][y]=='\0')
  {
    putchar('\n');
    return ;
  }
  putchar(G[x][y]);
  print(x+dx,y+dy,dx,dy);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  int n,m;

  while (scanf("%d %d",&n,&m)==2 && n>0)
  {
    memset(G,'*',sizeof G);
    for (int i=1;i<=n;i++) scanf("%s",&G[i][1]);

    memset(id,0,sizeof id);
    int cnt=0;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (G[i][j]!='*' && (G[i][j-1]=='*' || G[i-1][j]=='*'))
          id[i][j]=++cnt;       

    if (__>0) putchar('\n');
    
    printf("puzzle #%d:\n",++__);
    
    puts("Across");
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (G[i][j-1]=='*' && G[i][j]!='*') printf("%3d.",id[i][j]),print(i,j,0,1);
    
    puts("Down");
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (G[i-1][j]=='*' && G[i][j]!='*') printf("%3d.",id[i][j]),print(i,j,1,0);
  }


  return 0;
}
