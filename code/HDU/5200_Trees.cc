/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 04 Apr 2015 07:36:25 PM CST
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
#define maxn 50007

using namespace std;

int pre[maxn];
bool vis[maxn];

struct tree
{
  int h,p;
  bool operator < (const tree &rhs) const
  {
    return h>rhs.h;
  }
}t[maxn];

struct query
{
  int q,p;
  bool operator < (const query &rhs) const
  {
    return q>rhs.q;
  }
}q[maxn];

inline int readint()
{
  bool flag=false;
  char ch=getchar();
  int data=0;
  while (ch<'0' || ch>'9')
  {
    if (ch=='-') flag=true;
    ch=getchar();
  }
  do
  {
    data=data*10+ch-'0';
    ch=getchar();
  } while ('0'<=ch && ch<='9');
  if (flag) return -data;
  return data;
}

int root(int x)
{
  if (pre[x]==x) return x;
  return pre[x]=root(pre[x]);
}

inline bool same(int x,int y)
{
  return root(x)==root(y);
}

int cnt;

inline void merge(int x,int y)
{
  if (same(x,y)) return ;
  pre[root(x)]=root(y);
  cnt--;
}

int res[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;

  while (scanf("%d%d",&n,&m)==2)
  {
    for (int i=0;i<n;i++)
    {
      pre[i+1]=i+1;
      int h=readint();
      t[i]=(tree){h,i+1};
    }
    
    for (int i=0;i<m;i++) 
    {
      int h=readint();
      q[i]=(query){h,i};
    }

    sort(t,t+n);
    sort(q,q+m);

    memset(vis,0,sizeof vis);

    cnt=0;

    for (int i=0,j=0;i<m;i++)
    {
      while (j<n && t[j].h>q[i].q)
      {
        cnt++;
        int p=t[j].p;
        if (vis[p-1]) merge(p,p-1);
        if (vis[p+1]) merge(p,p+1);
        vis[p]=true;
        j++;
      }

      res[q[i].p]=cnt;
    }

    for (int i=0;i<m;i++) printf("%d\n",res[i]);
  }



  return 0;
}
