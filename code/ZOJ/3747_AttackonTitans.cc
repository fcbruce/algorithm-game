/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Jul 2015 06:52:32 PM CST
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

long long r[maxn],p[maxn],g[maxn];

const long long mod = 1000000007ll;

long long dp(int n,int m,int k)
{
  r[0]=p[0]=g[0]=1;

  for (int i=1;i<=n;i++)
  {
    if (i==1) r[i]=p[i]=g[i]=1;
    else r[i]=p[i]=g[i]=r[i-1]+p[i-1]+g[i-1];
    if (i==k+1) r[i]--;
    if (i>k+1) r[i]-=p[i-k-1]+g[i-k-1];
    if (i==m+1) g[i]--;
    if (i>m+1) g[i]-=r[i-m-1]+p[i-m-1];
    r[i]%=mod;
    p[i]%=mod;
    g[i]%=mod;
    if (r[i]<0) r[i]+=mod;
    if (p[i]<0) p[i]+=mod;
    if (g[i]<0) g[i]+=mod;
  }

  return ((r[n]+p[n]+g[n])%mod+mod)%mod;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,k;

  while (scanf("%d%d%d",&n,&m,&k)==3)
  {
    r[0]=p[0]=g[0]=1;

    long long res=(dp(n,n,k)-dp(n,m-1,k)%mod+mod)%mod;

    printf("%lld\n",res);
  }


  return 0;
}
