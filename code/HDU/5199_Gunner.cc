/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 04 Apr 2015 07:22:04 PM CST
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

int h[maxn];
int a[maxn];
int x[maxn];

int xn;

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

  int n,m;

  while (scanf("%d%d",&n,&m)==2) 
  {
    xn=0;
    for (int i=0;i<n;i++)
    {
      x[i]=a[i]=readint();

    }


    sort(x,x+n);
    xn=unique(x,x+n)-x;
    memset(h,0,sizeof h);
    for (int i=0;i<n;i++) 
    {
      int p=lower_bound(x,x+xn,a[i])-x;
      h[p]++;
    }

    for (int i=0;i<m;i++) 
    {
      int q=readint();
      int p=lower_bound(x,x+xn,q)-x;
      if (x[p]!=q) 
      {
        puts("0");
        continue;
      }
      printf("%d\n",h[p]);
      h[p]=0;
    }

    
  }



  return 0;
}
