/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 11 Aug 2015 08:45:46 AM CST
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
#define maxn 20007

using namespace std;

int fir[maxn];
int u[maxn],v[maxn],nex[maxn];
int e_max;

int dp[maxn][3];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int fa)
{
  dp[s][0]=dp[s][1]=0;
  dp[s][2]=10007;

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
  {
    dfs(v[e],s);
    dp[s][0]+=min(dp[v[e]][0],dp[v[e]][1]);
    dp[s][1]+=dp[v[e]][2];
  }

  dp[s][0]++;

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
    dp[s][2]=min(dp[s][2],dp[s][1]-dp[v[e]][2]+dp[v[e]][0]);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,u,v;i<n;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v);
      add_edge(v,u);
    }

    dfs(1,-1);

    printf("%d\n",min(dp[1][0],dp[1][2]));

    scanf("%d",&n);
    if (n==-1) break;
  }



  return 0;
}
