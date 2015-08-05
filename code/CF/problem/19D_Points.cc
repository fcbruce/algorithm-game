/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 05 Aug 2015 03:07:02 PM CST
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
#define maxn 200007

using namespace std;

char cmd[maxn][7];
pair<int,int> p[maxn],x[maxn];
int maxv[maxn<<2];

void update(int p,int v,int k,int l,int r)
{
  if (l+1==r)
  {
    maxv[k]=v;
    return ;
  }

  int m=l+r>>1;
  if (p<m) update(p,v,k*2+1,l,m);
  else update(p,v,k*2+2,m,r);

  maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
}

pair<int,int> query(int p,pair<int,int> point,int k,int l,int r)
{
  if (maxv[k]<point.second) return {-1,-1};
  if (l+1==r) return {x[l].first,maxv[k]};

  int m=l+r>>1;
  auto res=make_pair(-1,-1);
  if (p<m) res=query(p,point,k*2+1,l,m);
  if (res.first==-1) res=query(p,point,k*2+2,m,r);
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  memset(maxv,-1,sizeof maxv);

  for (int i=0;i<n;i++)
  {
    scanf("%s%d%d",cmd[i],&p[i].first,&p[i].second);
    if (cmd[i][0]=='f')
    {
      p[i].first++;
      p[i].second++;
    }
    x[i]=p[i];
  }

  sort(x,x+n);
  int xn=unique(x,x+n)-x;

  for (int i=0;i<n;i++)
  {
    int pos=lower_bound(x,x+xn,p[i])-x;

    switch (cmd[i][0])
    {
      case 'a':update(pos,p[i].second,0,0,xn);
               break;
      case 'r':update(pos,-1,0,0,xn);
               break;
      case 'f':auto res=query(pos,p[i],0,0,xn);
               if (res.first!=-1) printf("%d %d\n",res.first,res.second);
               else puts("-1");
               break;
    }
  }



  return 0;
}
