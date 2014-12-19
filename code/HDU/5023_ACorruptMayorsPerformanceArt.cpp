/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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
#define maxn 1000007

using namespace std;

int setv[maxn<<2],col[maxn<<2];

inline void
pushdown(int k)
{
  int lc=k*2+1,rc=k*2+2;
  
  if (setv[k]>0)
  {
    col[lc]=col[rc]=setv[lc]=setv[rc]=setv[k];
    setv[k]=0;
  }
}

inline void
pushup(int k)
{
  int lc=k*2+1,rc=k*2+2;
  
  col[k]=col[lc]|col[rc];
}

void
update(int a,int b,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    col[k]=setv[k]=1<<v;
    return ;
  }

  pushdown(k);
  
  update(a,b,v,k*2+1,l,l+r>>1);
  update(a,b,v,k*2+2,l+r>>1,r);
  
  pushup(k);
}

int
query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return col[k];
  
  pushdown(k);
  
  return query(a,b,k*2+1,l,l+r>>1)|query(a,b,k*2+2,l+r>>1,r);
}


int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n,m;
  int a,b,c;
  char op[5];
  
  while (scanf("%d%d",&n,&m),n||m)
  {
    update(0,n,2,0,0,n);
    
    while (m--)
    {
      scanf("%s",op);
      if (op[0]=='P')
      {
        scanf("%d%d%d",&a,&b,&c);
        a--;
        update(a,b,c,0,0,n);
      }
      else
      {
        scanf("%d%d",&a,&b);
        a--;
        int k=query(a,b,0,0,n);
        bool first=true;
        for (int i=1;i<=30;i++)
        {
          if (k&1<<i)
          {
            if (!first) putchar(' ');
            first=false;
            printf("%d",i);
          }
        }
        putchar('\n');
      }
    }
  }
  
  return 0;
}



