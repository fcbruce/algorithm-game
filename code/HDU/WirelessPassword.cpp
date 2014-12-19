/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 20 Nov 2014 10:01:45 AM CST
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
#define maxn 255

using namespace std;

const int mod = 20090717;

int dp[2][maxn][1024];

inline int add(int a,int b)
{
  return (a+b)%mod;
}

int q[maxn];

const int maxsize = 26;
struct ACauto
{
  int ch[maxn][maxsize];
  int val[maxn],nex[maxn],last[maxn];
  int sz;

  ACauto()
  {
    memset(ch[0],0,sizeof ch[0]);
    val[0]=0;
    sz=1;
  }

  void clear()
  {
    memset(ch[0],0,sizeof ch[0]);
    val[0]=0;
    sz=1;
  }

  int idx(char c)
  {
    return c-'a';
  }

  void insert(const char *s,int v)
  {
    int u=0;
    for (int i=0;s[i]!='\0';i++)
    {
      int c=idx(s[i]);
      if (ch[u][c]==0)
      {
        memset(ch[sz],0,sizeof ch[sz]);
        val[sz]=0;
        ch[u][c]=sz++;
      }
      u=ch[u][c];
    }
    val[u]=v;
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

  int calc(int x)
  {
    int cnt=0;
    for (int i=0;i<32;i++)
      if (x&(1<<i)) cnt++;
    return cnt;
  }
  
  int DP(int l,int m,int k)
  {
    memset(dp,0,sizeof dp);
    dp[0][0][0]=1;
    int x=1;
    for (int i=0;i<l;i++,x^=1)
    {
      memset(dp[x],0,sizeof dp[x]);
      for (int j=0;j<sz;j++)
      {
        for (int s=0;s<m;s++)
        {
          if (dp[x^1][j][s]==0) continue;
          for (int c=0;c<maxsize;c++)
          {
            int &cur=dp[x][ch[j][c]][s|val[ch[j][c]]];
            cur=add(cur,dp[x^1][j][s]);
          }
        }
      }
    }

    int total=0;

    for (int i=0;i<m;i++)
    {
      if (calc(i)<k) continue;
      for (int j=0;j<sz;j++)
        total=add(total,dp[x^1][j][i]);
    }

    return total;
  }
}acauto;

char str[16];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,k;

  while (scanf("%d%d%d",&n,&m,&k),n||m||k)
  {
    acauto.clear();
    for (int i=0;i<m;i++)
    {
      scanf("%s",str);
      acauto.insert(str,1<<i);
    }

    acauto.get_fail();

    printf("%d\n",acauto.DP(n,1<<m,k));
  }


  return 0;
}
