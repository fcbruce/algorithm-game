/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 06:20:45 PM CST
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

int q[maxn];
int a[maxn];
int le[maxn];
int ri[maxn];
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

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  while (scanf("%d",&n),n!=0)
  {
    for (int i=0;i<n;i++) a[i]=readint();

    le[0]=0;
    for (int i=1;i<n;i++)
    {
      le[i]=i;
      while (le[i]-1>=0 && a[le[i]-1]>=a[i]) le[i]=le[le[i]-1];
    }

    ri[n-1]=n-1;
    for (int i=n-1;i>=0;i--)
    {
      ri[i]=i;
      while (ri[i]+1<n && a[ri[i]+1]>=a[i]) ri[i]=ri[ri[i]+1];
    }

    long long res=0ll;

    for (int i=0;i<n;i++)
    {
      res=max(res,(long long)(ri[i]-le[i]+1)*a[i]);
    }

    printf(lld"\n",res);

  }



  return 0;
}
