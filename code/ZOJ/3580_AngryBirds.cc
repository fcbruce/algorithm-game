/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 01 Aug 2015 09:20:23 PM CST
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
#define maxn 65536

using namespace std;

int dp[maxn];
vector<int> status;

inline int dcmp(double k)
{
  return fabs(k)<eps ? 0 : k>0 ? 1 : -1;
}

struct Range
{
  double a,b;
  bool operator < (const Range &rhs) const
  {
    return dcmp(a-rhs.a) < 0;
  }
}ang[32];

int dfs(int s)
{
  if (s==0) return 0;
  if (dp[s]!=INF) return dp[s];

  for (auto hit : status)
  {
    int tar=s&(~hit);
    if (tar!=s) dp[s]=min(dp[s],dfs(tar)+1);
  }

  return dp[s];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  double v,y;
  double range;

  const double g = 9.8;

  auto pos=[&](double a)
  {
    if (dcmp(a)<0 || dcmp(a-PI/2.0)>0) return 0;
    for (int i=0;i<n;i++) if (dcmp(a-ang[i].b)<0) return dcmp(ang[i].a-a)<0 ? 1<<i : 0;
    return 0;
  };

  auto X=[&](double a)
  {
    double vy=v*cos(a);
    double vx=v*sin(a);
    double t=(-vy+sqrt(sqr(vy)+2*g*y))/(g);
    return t*vx;
  };

  auto calc=[&](double p)
  {
    if (dcmp(p-range)>=0) return PI/2.0;
    double l=0,r=PI/2.0;
    while (dcmp(r-l)>0)
    {
      double mid=(l+r)/2.0;
      if (dcmp(X(mid)-p) > 0) r=mid;
      else l=mid;
    }
    return (l+r)/2.0;
  };

  while (scanf("%d%lf%lf",&n,&v,&y)==3)
  {
    range=X(PI/2.0);
    bool ok=true;
    double gap=0.01;

    for (int i=0;i<n;i++)
    {
      double x1,x2;
      scanf("%lf%lf",&x1,&x2);
      if (dcmp(x1-range)>0) ok=false;
      if (!ok) continue;
      ang[i].a=calc(x1);
      ang[i].b=calc(x2);
      gap=min(gap,ang[i].b-ang[i].a);
    }

    if (!ok) 
    {
      puts("-1");
      continue;
    }

    gap/=3;

    sort(ang,ang+n);

    status.clear();

    for (int i=0;i<n;i++) for (double a=ang[i].a+eps;dcmp(a-ang[i].b)<0;a+=gap)
    {
      int s=1<<i;
      int s0=pos(a-PI/6.0);
      int s1=pos(a-PI/12.0);
      int s2=pos(a+PI/12.0);
      int s3=pos(a+PI/6.0);
      status.push_back(s0|s1|s);
      status.push_back(s1|s|s2);
      status.push_back(s|s2|s3);
    }

    sort(status.begin(),status.end());
    int cnt=unique(status.begin(),status.end())-status.begin();
    status.resize(cnt);
    
    memset(dp,0x3f,sizeof dp);
    int res=dfs((1<<n)-1);
    if (res==INF) res=-1;
    printf("%d\n",res);
  }



  return 0;
}
