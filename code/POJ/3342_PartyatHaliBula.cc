/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 05 Aug 2015 01:55:25 PM CST
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
#define maxn 233

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

map<string,int> name;

char s1[maxn],s2[maxn];

int dp[maxn][2];
bool uni[maxn][2];

inline int id(char *s)
{
  string tmp(s);

  if (name.count(tmp)==0) return name[tmp]=name.size();
  else return name[tmp];
}

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s)
{
  dp[s][0]=0;
  dp[s][1]=1;
  uni[s][0]=uni[s][1]=true;

  for (int e=fir[s];~e;e=nex[e])
  {
    dfs(v[e]);
    dp[s][0]+=max(dp[v[e]][1],dp[v[e]][0]);
    uni[s][0]&= dp[v[e]][1]==dp[v[e]][0]? false : 
      dp[v[e]][0]>dp[v[e]][1] ? uni[v[e]][0] : uni[v[e]][1];
    dp[s][1]+=dp[v[e]][0];
    uni[s][1]&= uni[v[e]][0];
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d",&n)==1 && n>0)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    name.clear();

    scanf("%s",s1);

    int root(id(s1));

    for (int i=1;i<n;i++)
    {
      scanf("%s%s",s1,s2);
      add_edge(id(s2),id(s1));
    }

    dfs(root);

    int res;
    bool unique;

    if (dp[root][0]==dp[root][1])
    {
      res=dp[root][0];
      unique=false;
    }
    else if (dp[root][0]>dp[root][1])
    {
      res=dp[root][0];
      unique=uni[root][0];
    }
    else
    {
      res=dp[root][1];
      unique=uni[root][1];
    }

    printf("%d %s\n",res,unique?"Yes":"No");
  }



  return 0;
}
