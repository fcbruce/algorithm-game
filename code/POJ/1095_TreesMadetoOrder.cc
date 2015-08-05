/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 05 Aug 2015 04:44:34 PM CST
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

long long c[23];
long long s[23];

void init()
{
  c[0]=1;
  s[0]=1;
  c[1]=1;
  s[1]=2;
  c[2]=2;
  s[2]=4;
  for (int i=3;i<23;i++)
  {
    c[i]=0;
    for (int j=0;j<i;j++) c[i]+=c[j]*c[i-1-j];
    s[i]=s[i-1]+c[i];
  }
}

void solve(int n,bool in)
{
  if (n==0) return ;
  if (n==1)
  {
    if (in) putchar('(');
    putchar('X');
    if (in) putchar(')');
    return ;
  }
  
  int cnt=0;
  for (int i=0;i<23;i++)
  {
    if (s[i]>n) break;
    cnt=i;
  }
  n-=s[cnt];
  int lc=-1;
  for (int i=0;i<=cnt;i++)
  {
    if (c[i]*c[cnt-i]>n) break;
    n-=c[i]*c[cnt-i];
    lc=i;
  }
  lc++;
  if (in) putchar('(');
  solve(n/c[cnt-lc]+(lc-1<0?0:s[lc-1]),true);
  putchar('X');
  solve(n%c[cnt-lc]+(cnt-lc-1<0?0:s[cnt-lc-1]),true);
  if (in) putchar(')');

}

int main()
{
#ifdef FCBRUCE
  //freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  init();

  int n;
  
  while (scanf("%d",&n)==1 && n!=0)
  {
    solve(n,false);
    puts("");
  }



  return 0;
}
