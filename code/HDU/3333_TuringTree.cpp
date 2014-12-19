/*
 *
 * Author : fcbruce
 *
 * Time : Wed 08 Oct 2014 08:08:29 PM CST
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

#define maxm 100007
#define maxn 30007 

using namespace std;

int a[maxn];
int A[maxn];
int rec[maxn];
int pos[maxn];
long long sum[maxn<<2];
long long ans[maxm];

struct _query
{
  int l,r,id;
  bool operator < (const _query &_)const
  {
    return r<_.r;
  }
}q[maxm];

inline void pushup(int k)
{
  sum[k]=sum[k*2+1]+sum[k*2+2];
}

void update(int p,int v,int k,int l,int r)
{
  if (r-l==1)
  {
    sum[k]=v;
    return ;
  }

  int m=l+r>>1;
  if (p<m)
    update(p,v,k*2+1,l,m);
  else
    update(p,v,k*2+2,m,r);

  pushup(k);
}

long long query(int a,int b,int k,itn l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return sum[k];

  return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
      scanf("%d",a+i);
      A[i]=a[i];
    }

    sort(A,A+n);
    int AN=unique(A,A+n)-A;
    
    memset(rec,-1,sizeof rec);

    for (int i=0;i<n;i++)
    {
      int x=lower_bound(A,A+AN,a[i])-A;
      pos[i]=rec[x];
      rec[x]=i;
    }

    int Q;
    scanf("%d\n",&Q);

    for (int i=0,a,b;i<Q;i++)
    {
      scanf("%d%d",&a,&b);
      q[i]=(_query){a-1,b,i};
    }

    sort(q,q+Q);

    memset(sum,0,sizeof sum);

    for (int i=0,j=0;i<Q;i++)
    {
      while (j<q[i].r)
      {
        update(j,a[j],0,0,n);
        if (pos[j]!=-1) update(pos[j],0,0,0,n);
        j++;
      }

      ans[q[i].id]=query(q[i].l,q[i].r,0,0,n);
    }

    for (int i=0;i<Q;i++) printf(lld "\n",ans[i]);
  }

  return 0;
}
