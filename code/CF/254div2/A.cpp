/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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
#define maxn 111

using namespace std;

char G[maxn][maxn];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void
dfs(int x,int y,int type)
{
  G[x][y]=type?'B':'W';
  for (int i=0;i<4;i++)
  {
    int tx=x+dx[i],ty=y+dy[i];
    if (G[tx][ty]=='.') dfs(tx,ty,type^1);
  }
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n,m;
  memset(G,'-',sizeof G);
  
  scanf("%d%d",&n,&m);
  
  for (int i=1;i<=n;i++)
  {
    scanf("%s",G[i]+1);
  }
  
  for (int i=1;i<=n;i++)
  {
    for (int j=1;j<=m;j++)
    {
      if (G[i][j]=='.') dfs(i,j,0);
      putchar(G[i][j]);
    }
    putchar('\n');
  }
  
  
  return 0;
}



