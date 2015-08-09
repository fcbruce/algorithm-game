/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 10:11:02 AM CST
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
#define maxn 6666

using namespace std;

int dp[maxn][2];

int fir[maxn];
int u[maxn],v[maxn],nex[maxn];
int e_max;

int rate[maxn],in[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s)
{
  dp[s][0]=0;
  dp[s][1]=rate[s];

  for (int e=fir[s];~e;e=nex[e])
  {
    dfs(v[e]);
    dp[s][0]+=max(dp[v[e]][0],dp[v[e]][1]);
    dp[s][1]+=dp[v[e]][0];
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  e_max=0;
  memset(fir,-1,sizeof fir);

  memset(in,0,sizeof in);

  int n;
  scanf("%d",&n);

  for (int i=1;i<=n;i++) scanf("%d",rate+i);

  for (int i=1,u,v;i<n;i++)
  {
    scanf("%d%d",&v,&u);
    add_edge(u,v);
    in[v]++;
  }

  for (int i=1;i<=n;i++) if (in[i]==0)
  {
    dfs(i);
    printf("%d\n",max(dp[i][0],dp[i][1]));
    break;
  }

  return 0;
}
