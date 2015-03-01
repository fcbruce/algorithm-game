/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 01 Mar 2015 01:12:25 PM CST
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

int Left[maxn],Right[maxn];

inline void link(int L,int R)
{
  Right[L]=R;
  Left[R]=L;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  int n,m;

  while (scanf("%d %d",&n,&m)==2)
  {

    for (int i=1;i<=n;i++)
    {
      Left[i]=i-1;
      Right[i]=(i+1)%(n+1);
    }
    Right[0]=1;
    Left[0]=n;
    int op,X,Y;
    bool inv=false;

    while (m--)
    {
      scanf("%d",&op);
      if (op==4)
      {
        inv=!inv;
        continue;
      }

      scanf("%d %d",&X,&Y);

      if (op==3 && Right[Y]==X) swap(X,Y);
      if (op!=3 && inv) op=3-op;
      if (op==1 && X==Left[Y]) continue;
      if (op==2 && X==Right[Y]) continue;

      int LX=Left[X],RX=Right[X],LY=Left[Y],RY=Right[Y];
      if (op==1)
      {
        link(LX,RX);
        link(LY,X);
        link(X,Y);
      }
      else if (op==2)
      {
        link(LX,RX);
        link(Y,X);
        link(X,RY);
      }
      else if (op==3)
      {
        if (Right[X]==Y)
        {
          link(LX,Y);
          link(Y,X);
          link(X,RY);
        }
        else
        {
          link(LX,Y);
          link(Y,RX);
          link(LY,X);
          link(X,RY);
        }
      }
    }

    int b=0;
    long long res=0;
    for (int i=1;i<=n;i++)
    {
      b=Right[b];
      if (i%2==1) res+=b;
    }
    if (inv && n%2==0) res=(long long ) n*(n+1)/2-res;
    printf("Case %d: %lld\n",++__,res);
  }



  return 0;
}
