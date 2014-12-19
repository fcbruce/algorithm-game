/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 29 Nov 2014 11:11:24 PM CST
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

int maxv[maxn<<2],addv[maxn<<2];
int x[maxn],y[maxn];
int A[maxn<<2];

inline void pushdown(int k)
{
  int lc=k*2+1,rc=k*2+2;
  addv[lc]+=addv[k];
  addv[rc]+=addv[k];
  maxv[lc]+=addv[k];
  maxv[rc]+=addv[k];
  addv[k]=0;
}

inline void pushup(int k)
{
  maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
}

void update(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    addv[k]++;
    maxv[k]++;
    return ;
  }

  pushdown(k);

  update(a,b,k*2+1,l,l+r>>1);
  update(a,b,k*2+2,l+r>>1,r);

  pushup(k);
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
    int n,cnt=0;
    scanf("%d",&n);

    memset(addv,0,sizeof addv);
    memset(maxv,0,sizeof maxv);

    for (int i=0;i<n;i++)
    {
      scanf("%d%d",x+i,y+i);
      A[cnt++]=x[i];
      A[cnt++]=y[i];
    }

    sort(A,A+cnt);
    cnt=unique(A,A+cnt)-A;

    for (int i=0;i<n;i++)
    {
      int a=lower_bound(A,A+cnt,x[i])-A;
      int b=lower_bound(A,A+cnt,y[i])-A;
      b++;

      update(a,b,0,0,cnt);
    }

    printf("%d\n",maxv[0]);

  }



  return 0;
}
