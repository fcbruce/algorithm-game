/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Aug 2015 07:05:21 PM CST
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
#define maxn 202

using namespace std;

map<string,int> name;

int fir[maxn];
int u[maxn],v[maxn],nex[maxn];
int e_max;

int dp[maxn][2];
bool isunique[maxn][2];

char s1[1024],s2[1024];

inline int id(char *s)
{
  string tmp(s);
  if (name.count(tmp)==0) return name[tmp]=name.size();
  return name[tmp];
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
  isunique[s][0]=isunique[s][1]=true;

  for (int e=fir[s];~e;e=nex[e])
  {
    dfs(v[e]);
    if (dp[v[e]][0]==dp[v[e]][1])
    {
      dp[s][0]+=dp[v[e]][0];
      isunique[s][0]=false;
    }
    else if (dp[v[e]][0]>dp[v[e]][1])
    {
      dp[s][0]+=dp[v[e]][0];
      isunique[s][0]&=isunique[v[e]][0];
    }
    else
    {
      dp[s][0]+=dp[v[e]][1];
      isunique[s][0]&=isunique[v[e]][1];
    }

    dp[s][1]+=dp[v[e]][0];
    isunique[s][1]&=isunique[v[e]][0];
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1 && n!=0)
  {
    name.clear();
    e_max=0;
    memset(fir,-1,sizeof fir);

    scanf("%s",s1);
    int root=id(s1);
    for (int i=1;i<n;i++)
    {
      scanf("%s%s",s2,s1);
      add_edge(id(s1),id(s2));
    }

    dfs(root);

    if (dp[root][0]==dp[root][1])
      printf("%d %s\n",dp[root][0],"No");
    else
    {
      int choice=max_element(dp[root],dp[root]+2)-dp[root];
      printf("%d %s\n",dp[root][choice],isunique[root][choice]?"Yes":"No");
    }
  }



  return 0;
}
