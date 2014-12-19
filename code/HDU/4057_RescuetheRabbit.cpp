/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 13 Nov 2014 08:23:41 PM CST
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
#define maxn 1007

using namespace std;

char gene[17][233];
int w[17];
int dp[2][maxn][2333];

int q[maxn<<1];

const int maxsize = 4;
struct ACauto
{
  int ch[maxn][maxsize];
  int val[maxn],last[maxn],nex[maxn];
  int sz;

  ACauto()
  {
    sz=1;
    val[0]=0;
    memset(ch[0],0,sizeof ch[0]);
  }

  void clear()
  {
    sz=1;
    val[0]=0;
    memset(ch[0],0,sizeof ch[0]);
  }

  int idx(char c)
  {
    switch (c)
    {
      case 'A': return 0;
      case 'T': return 1;
      case 'C': return 2;
      case 'G': return 3;
    }
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
    for (itn c=0;c<maxsize;c++)
    {
      int u=ch[0][c];
      if (u!=0)
      {
        nex[u]=0;
        q[++r]=u;
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

  int calc(int x,int n)
  {
    int score=0;
    for (int i=0;i<n;i++)
      if (x&(1<<i)) score+=w[i];
    return score;
  }

  int go(int l,int n)
  {
    memset(dp,0,sizeof dp);
    dp[0][0][0]=true;

    int x=1;
    for (int i=1;i<=l;i++,x^=1)
    {
      memset(dp[x],0,sizeof dp[x]);
      for (int j=0;j<sz;j++)
        for (int k=0;k<4;k++)
          for (int l=0;l<(1<<n);l++)
            if (dp[x^1][j][l]) dp[x][ch[j][k]][l|val[ch[j][k]]]=true;
    }

    int MAX=-1;
    for (int i=0;i<(1<<n);i++)
    {
      int cur=calc(i,n);
      if (cur<=MAX) continue;
      for (int j=0;j<=sz;j++)
        if (dp[x^1][j][i])
        {
          MAX=cur;
          break;
        }
    }

    return MAX;
  }
}acauto;


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,l;

  while (scanf("%d%d",&n,&l)==2)
  {
    acauto.clear();

    for (int i=0;i<n;i++)
    {
      scanf("%s %d",gene[i],w+i);
      acauto.insert(gene[i],1<<i);
    }

    acauto.get_fail();

    int MAX=acauto.go(l,n);

    if (MAX>=0) printf("%d\n",MAX);
    else puts("No Rabbit after 2012!");
  }


  return 0;
}
