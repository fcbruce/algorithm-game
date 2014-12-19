/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 18 Nov 2014 11:17:49 AM CST
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
#define maxn 1024

using namespace std;

int q[maxn];

const int maxsize = 4;
struct Acauto
{
  int ch[maxn][maxsize];
  bool val[maxn];
  int last[maxn],nex[maxn];
  int sz;
  int dp[2][maxn];

  Acauto()
  {
    memset(ch[0],0,sizeof ch[0]);
    val[0]=false;
    sz=1;
  }

  void clear()
  {
    memset(ch[0],0,sizeof ch[0]);
    val[0]=false;
    sz=1;
  }

  int idx(const char c)
  {
    if (c=='A') return 0;
    if (c=='T') return 1;
    if (c=='C') return 2;
    return 3;
  }

  void insert(const char *s)
  {
    int u=0;
    for (int i=0;s[i]!='\0';i++)
    {
      int c=idx(s[i]);
      if (ch[u][c]==0)
      {
        memset(ch[sz],0,sizeof ch[sz]);
        val[sz]=false;
        ch[u][c]=sz++;
      }
      u=ch[u][c];
    }
    val[u]=true;
  }

  void get_fail()
  {
    int f=0,r=-1;
    nex[0]=0;
    for (int c=0;c<maxsize;c++)
    {
      int u=ch[0][c];
      if (u!=0)
      {
        nex[u]=0;
        q[++r]=u;
        last[u]=0;
      }
    }

    while (f<=r)
    {
      int x=q[f++];
      for (int c=0;c<maxsize;c++)
      {
        int u=ch[x][c];
        if (u==0)
        {
          ch[x][c]=ch[nex[x]][c];
          continue;
        }
        q[++r]=u;
        int v=nex[x];
        nex[u]=ch[v][c];
        val[u]|=val[nex[u]];
      }
    }
  }

  int DP(const char *T)
  {
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    int x=1;
    for (int i=0;T[i]!='\0';i++,x^=1)
    {
      memset(dp[x],0x3f,sizeof dp[x]);
      int c=idx(T[i]);
      for (int j=0;j<sz;j++)
      {
        if (dp[x^1][j]==INF) continue;
        for (int k=0;k<4;k++)
        {
          if (val[ch[j][k]]) continue;
          int add=k==c?0:1;
          dp[x][ch[j][k]]=min(dp[x][ch[j][k]],dp[x^1][j]+add);
        }
      }
    }

    int MIN=INF;
    for (int i=0;i<sz;i++)
      MIN=min(MIN,dp[x^1][i]);
    if (MIN==INF) MIN=-1;
    return MIN;
  }
}acauto;

char DNA[1024];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,__=0;
  
  while (scanf("%d",&n),n!=0)
  {
    acauto.clear();
    for (int i=0;i<n;i++)
    {
      scanf("%s",DNA);
      acauto.insert(DNA);
    }

    acauto.get_fail();

    scanf("%s",DNA);

    printf("Case %d: %d\n",++__,acauto.DP(DNA));
  }


  return 0;
}
