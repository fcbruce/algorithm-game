}
/*
 *
 * Author : fcbruce
 *
 * Time : Mon 06 Oct 2014 01:06:30 PM CST
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
#define maxn 100007

using namespace std;

int fib[maxn];
struct _edge
{
  int u,v,w;
  bool operator < (const _edge &_)const
  {
    return w<_.w;
  }
}edge[maxm];

int pre[maxn];

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

bool same(int x,int y)
{
  return root(x)==root(y);
}

void _merge(itn x,int y)
{
  pre[root(x)]=root(y);
}

int cnt,fib_cnt;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T,__=0;
  scanf("%d\n",&T_T);

  fib[0]=1;
  fib[1]=1;
  fib_cnt=2;
  for (int i=2;;i++)
  {
    fib[i]=fib[i-1]+fib[i-2];
    fib_cnt++;
    if (fib[i]>100000) break;
  }

  while (T_T--)
  {
    printf("Case #%d: ",++__);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) pre[i]=i;
    cnt=n;
    for (int i=0,u,v,w;i<m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      if (!same(u,v)) {_merge(u,v);cnt--;}
      edge[i]=(_edge){u,v,w};
    }

    if (cnt!=1)
    {
      printf("No\n");
      continue;
    }

    sort(edge,edge+m);

    for (int i=1;i<=n;i++) pre[i]=i;
    int MIN=0;
    cnt=n;
    for (int i=0,u,v,w;i<m;i++)
    {
      u=edge[i].u;v=edge[i].v;w=edge[i].w;
      if (!same(u,v))
      {
        _merge(u,v);
        MIN+=w;
        cnt--;
        if (cnt==1) break;
      }
    }

    for (int i=1;i<=n;i++) pre[i]=i;
    int MAX=0;
    cnt=n;
    for (int i=m-1,u,v,w;i>=0;i--)
    {
      u=edge[i].u;v=edge[i].v;w=edge[i].w;
      if (!same(u,v))
      {
        _merge(u,v);
        MAX+=w;
        cnt--;
        if (cnt==1) break;
      }
    }

    int idmin=lower_bound(fib,fib+fib_cnt,MIN)-fib;
    int idmax=lower_bound(fib,fib+fib_cnt,MAX)-fib;

    if (fib[idmin]!=MIN && fib[idmax]!=MAX && idmin==idmax)
      puts("No");
    else
      puts("Yes");
    
  }



  return 0;
}
