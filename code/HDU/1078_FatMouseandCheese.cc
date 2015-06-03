/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 03 Jun 2015 08:47:56 PM CST
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
#define maxn 107

using namespace std;

int G[maxn][maxn],dp[maxn][maxn];
int n,k;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

inline bool in(int x,int y)
{
  return 0<=x && x<n && 0<=y && y<n;
}

int dfs(int x,int y)
{
  if (dp[x][y]!=-1) return dp[x][y];

  dp[x][y]=0;
  for (int i=0;i<4;i++) for (int j=1;j<=k;j++)
  {
    int tx=x+dx[i]*j,ty=y+dy[i]*j;
    if (in(tx,ty) && G[tx][ty]>G[x][y]) dp[x][y]=max(dp[x][y],dfs(tx,ty));
  }

  return dp[x][y]+=G[x][y];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  while (scanf("%d%d",&n,&k),n!=-1 && k!=-1)
  {
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",G[i]+j);

    memset(dp,-1,sizeof dp);

    printf("%d\n",dfs(0,0));
  }




  return 0;
}
