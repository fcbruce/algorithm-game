/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 21 Oct 2014 05:09:39 PM CST
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

int dp[100][100];
int x[100],y[100],z[100];
int v[100];
int vn,cnt;

bool try__(int a,int b,int h)
{
  bool update=false;

  for (int i=a+1;i<=vn;i++)
  {
    for (int j=b+1;j<=vn;j++)
    {
      if (dp[a][b]<dp[i][j]+h)
      {
        dp[a][b]=dp[i][j]+h;
        update=true;
      }
      if (dp[b][a]<dp[j][i]+h)
      {
        dp[b][a]=dp[j][i]+h;
        update=true;
      }
    }
  }

  return update;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,__=0;

  while (scanf("%d",&n),n)
  {
    cnt=0;
    for (int i=0;i<n;i++)
    {
      scanf("%d%d%d",x+i,y+i,z+i);
      v[cnt++]=x[i];
      v[cnt++]=y[i];
      v[cnt++]=z[i];
    }

    sort(v,v+cnt);
    vn=unique(v,v+cnt)-v;

    memset(dp,0,sizeof dp);

    for (;;)
    {
      bool update=false;

      for (int i=0;i<n;i++)
      {
        int X=lower_bound(v,v+vn,x[i])-v;
        int Y=lower_bound(v,v+vn,y[i])-v;
        int Z=lower_bound(v,v+vn,z[i])-v;
        update|=try__(X,Y,z[i]);
        update|=try__(X,Z,y[i]);
        update|=try__(Z,Y,x[i]);
      }

      if (!update) break;
    }

    int MAX=0;
    for (int i=0;i<vn;i++)
      for (int j=0;j<vn;j++)
        MAX=max(MAX,dp[i][j]);

    printf("Case %d: maximum height = %d\n",++__,MAX);
  }


  return 0;
}
