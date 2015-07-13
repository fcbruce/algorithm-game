/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 13 Jul 2015 08:16:52 AM CST
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

long long dp[64][64][64];
int bit[64];

long long dfs(int pos,int c0,int c1,bool top,bool nonzero)
{
  if (pos==-1) return c1<=c0?1:0;
  if (!top && nonzero && dp[pos][c0][c1]!=-1) return dp[pos][c0][c1];
  long long res=0;
  if (nonzero) res+=dfs(pos-1,c0+1,c1,top && bit[pos]==0,true);
  else res+=dfs(pos-1,c0,c1,top && bit[pos]==0,false);
  if (!top || bit[pos]==1) res+=dfs(pos-1,c0,c1+1,top,true);
  if (!top && nonzero) return dp[pos][c0][c1]=res;
  return res;
}

long long calc(long long x)
{
  if (x==0) return 1;
  int pos=0;
  while (x!=0)
  {
    bit[pos++]=x%2;
    x/=2;
  }
  return dfs(pos-1,0,0,true,false);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  long long l,r;
  memset(dp,-1,sizeof dp);
  scanf(lld lld,&l,&r);
  printf(lld"\n",calc(r)-calc(l-1));


  return 0;
}
