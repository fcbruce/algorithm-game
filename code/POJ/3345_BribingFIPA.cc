/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 03:23:34 PM CST
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

#define maxm 404
#define maxn 202

using namespace std;

map<string,int> country;

int fir[maxn];
int u[maxn],v[maxn],nex[maxn];
int e_max;

int w[maxn],size[maxn],in[maxn];

int dp[maxn][maxn];

char buff[1024],s1[1024],s2[1024];

int n,m;

inline int id(char *s)
{
  string tmp(s);
  if (country.count(tmp)==0) return country[tmp]=country.size();
  return country[tmp];
}

inline void add_edge(int s,int t)
{
  int e=e_max++;
  in[t]++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s)
{
  memset(dp[s],0x3f,sizeof dp[s]);
  dp[s][0]=0;
  size[s]=1;

  for (int e=fir[s];~e;e=nex[e])
  {
    dfs(v[e]);
    size[s]+=size[v[e]];
    for (int i=size[s];i>=0;i--) for (int j=0;j<=size[v[e]];j++)
    {
      if (j>i) break;
      dp[s][i]=min(dp[s][i],dp[s][i-j]+dp[v[e]][j]);
    }
  }
  dp[s][size[s]]=w[s];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d %d",&n,&m)==2)
  {
    country.clear();
    w[0]=INF;
    e_max=0;
    memset(fir,-1,sizeof fir);

    memset(in,0,sizeof in);

    gets(buff);
    for (int i=0;i<n;i++)
    {
      gets(buff);
      stringstream ss(buff);
      ss>>s1;
      int u=id(s1);
      ss>>w[u];
      while (ss>>s2) add_edge(u,id(s2));
    }

    for (size_t i=1;i<=country.size();i++) if (in[i]==0)
      add_edge(0,i);

    dfs(0);

    int res=INF;
    for (int i=m;i<=size[0];i++) res=min(res,dp[0][i]);
    printf("%d\n",res);
  }



  return 0;
}
