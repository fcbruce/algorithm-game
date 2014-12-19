/*
 *
 * Author : fcbruce
 *
 * Time : Fri 03 Oct 2014 11:19:07 PM CST
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

int minv[maxn<<2];

void build(int k,int l,int r)
{
  if (r-l==1)
  {
    scanf("%d",minv+k);
    return ;
  }

  build(k*2+1,l,l+r>>1);
  build(k*2+2,l+r>>1,r);

  minv[k]=min(minv[k*2+1],minv[k*2+2]);
}

int query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return INF;
  if (a<=l && r<=b) return minv[k];

  return min(query(a,b,k*2+1,l,l+r>>1),query(a,b,k*2+2,l+r>>1,r));
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    printf("Scenario #%d:\n\n",++__);

    int n,m;
    scanf("%d%d",&n,&m);

    build(0,0,n);

    while (m--)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      a--;

      printf("%d\n\n",query(a,b,0,0,n));
    }
  }


  return 0;
}
