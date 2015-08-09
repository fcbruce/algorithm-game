/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 02:05:17 PM CST
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

#define maxm 207
#define maxn 107

using namespace std;

int n,k;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int apples[maxn];

int dp[maxn][maxm][2];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int fa)
{
  memset(dp[s],0,sizeof dp[s]);
  dp[s][0][0]=dp[s][0][1]=apples[s];

  for (int e=fir[s];~e;e=nex[e]) if (fa!=v[e])
  {
    dfs(v[e],s);
    for (int i=k;i>0;i--)
    {
      for (int j=1;j<=i;j++)
      {
        if (j==1)
        {
          dp[s][i][0]=max(dp[s][i][0],dp[s][i-j][1]+dp[v[e]][j-1][0]);
        }
        else
        {
          dp[s][i][0]=max(dp[s][i][0],max(dp[s][i-j][0]+dp[v[e]][j-2][1],dp[s][i-j][1]+dp[v[e]][j-1][0]));
          dp[s][i][1]=max(dp[s][i][1],dp[s][i-j][1]+dp[v[e]][j-2][1]);
        }
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",&n,&k)==2)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1;i<=n;i++) scanf("%d",apples+i);

    for (int i=1,u,v;i<n;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v);
      add_edge(v,u);
    }

    dfs(1,-1);

    int res=0;
    for (int i=0;i<=k;i++) res=max(res,max(dp[1][i][0],dp[1][i][1]));

    printf("%d\n",res);
  }



  return 0;
}
