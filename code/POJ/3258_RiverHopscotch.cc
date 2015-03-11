/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 06:45:53 PM CST
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
int ll,n,m;
int a[maxn];

bool check(int mid)
{
  int pos=1;
  int last=0;

  int x=m;

  while (pos<n)
  {
    if (a[pos]-a[last]>=mid)
    {
      last=pos;
    }
    else
    {
      x--;
    }
    pos++;

    if (x<0) return false;
    
  }

  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d%d%d",&ll,&n,&m);

  for (int i=0;i<n;i++) scanf("%d",a+i);
  a[n++]=0;
  a[n++]=ll;

  sort(a,a+n);

  int l=0,r=ll;
  int res=-1;

  while (l<=r)
  {
    itn mid=l+r>>1;

    if (check(mid))
    {
      res=mid;
      l=mid+1;
    }
    else r=mid-1;
  }
  
  printf("%d\n",res);


  return 0;
}
