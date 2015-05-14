/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 13 May 2015 07:58:03 PM CST
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
#define maxn 100007

using namespace std;

struct node
{
  int v,id;
  bool operator < (const node &rhs) const
  {
    return v<rhs.v;
  }
}a[maxn];

int b[maxn];

int l[maxn],r[maxn],pre[maxn];
long long sum[maxn];
bool vis[maxn];

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

inline bool same(int u,int v)
{
  return root(u)==root(v);
}

inline void merge(int u,int v)
{
  if (same(u,v)) return ;
  int ru=root(u),rv=root(v);

  pre[ru]=rv;
  sum[rv]+=sum[ru];
  l[rv]=min(l[rv],l[ru]);
  r[rv]=max(r[rv],r[ru]);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  for (int i=1;i<=n;i++) 
  {
    scanf("%d",b+i);
    a[i]={b[i],i};
  }

  sort(a+1,a+n+1);

  for (int i=1;i<=n;i++)
  {
    pre[i]=i;
    sum[i]=b[i];
    l[i]=r[i]=i;
    vis[i]=false;
  }

  int resl,resr;
  long long res=-1;
  for (int i=n;i>0;i--)
  {
    int p=a[i].id;
    vis[p]=true;
    if (vis[p-1]) merge(p-1,p);
    if (vis[p+1]) merge(p+1,p);

    long long val=a[i].v*sum[root(p)];

    if (val>res)
    {
      res=val;
      resl=l[root(p)];
      resr=r[root(p)];
    }
  }


  printf(lld"\n%d %d\n",res,resl,resr);



  return 0;
}
