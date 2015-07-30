/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 29 Jul 2015 09:02:45 PM CST
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
#define maxn 505

using namespace std;

map<pair<int,int>,int> group;
vector<pair<int,pair<int,int> > > g[maxn];

inline int id(pair<int,int> p)
{
  if (group.count(p)==0) return group[p]=group.size();
  return group[p];
}

vector<pair<int,int> > bag[maxn];

int dp[12345];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int x0,y0;
  int n,T;

  while (scanf("%d%d%d%d",&x0,&y0,&n,&T)==4)
  {
    group.clear();

    for (int i=0;i<n;i++)
    {
      int x,y,t,w;
      scanf("%d%d%d%d",&x,&y,&t,&w);
      x-=x0;
      y-=y0;
      int gcd=__gcd(abs(x),abs(y));
      x/=gcd;
      y/=gcd;
      g[id({x,y})].push_back({gcd,{t,w}});
    }

    for (size_t i=1;i<=group.size();i++)
    {
      sort(g[i].begin(),g[i].end());
      int t=0,w=0;
      bag[i].clear();
      for (auto &e : g[i])
      {
        t+=e.second.first;
        w+=e.second.second;
        bag[i].push_back({t,w});
      }
      g[i].clear();
    }

    memset(dp,0,sizeof dp);
    int MAX=0;
    for (size_t i=1;i<=group.size();i++)
      for (int j=T;j>=0;j--)
      {
        int res=dp[j];
        for (auto &e: bag[i])
          if (j>=e.first) res=max(res,dp[j-e.first]+e.second);
        dp[j]=res;
        MAX=max(res,MAX);
      }

    printf("%d\n",MAX);
  }




  return 0;
}
