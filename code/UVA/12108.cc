/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 15 Feb 2015 07:18:47 PM CST
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
#define maxn 

using namespace std;

int n;
int a[10],b[10];
int act[10];
bool sleeping[10];

inline int lcm(int a,int b)
{
  return a/__gcd(a,b)*b;
}

bool wake(int t)
{
  int cnt=0;
  for (int i=0;i<n;i++) if (!sleeping[i]) cnt++;
  if (cnt==n) return true;

  for (int i=0;i<n;i++) if (act[i]==t)
  {
    if (sleeping[i])
    {
      sleeping[i]=false;
      act[i]+=a[i];
    }
    else
    {
      if (n-cnt>n/2)
      {
        sleeping[i]=true;
        act[i]+=b[i];
      }
      else
      {
        act[i]+=a[i];
      }
    }
  }

  return false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (scanf("%d",&n),n!=0)
  {
    int m=1;
    for (int i=0,c;i<n;i++)
    {
      scanf("%d %d %d",a+i,b+i,&c);
      m=lcm(m,a[i]+b[i]);
      if (c<=a[i])
      {
        sleeping[i]=false;
        act[i]=1+(a[i]-c);
      }
      else
      {
        sleeping[i]=true;
        act[i]=1+(a[i]+b[i]-c);
      }
    }

    int ok=-1;
    for (int i=1;i<=m;i++)
    {
      if (wake(i))
      {
        ok=i;
        break;
      }
    }

    printf("Case %d: %d\n",++__,ok);
  }



  return 0;
}
