/*
 *
 * Author : fcbruce
 *
 * Time : Sat 04 Oct 2014 07:39:54 PM CST
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

#define maxm 128
#define maxn 100007

using namespace std;

bool found[507];
char T[10007];
char P[233];
int q[maxn<<2];

struct ACauto
{
  int ch[maxn][maxm];
  int val[maxn];
  int nex[maxn];
  int last[maxn];
  int cnt;
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

  int idx(const char ch)
  {
    return ch-'\0';
  }

  void insert(const char *s,int v=1)
  {
    int u=0;
    for (int i=0;s[i]!='\0';i++)
    {
      int c=idx(s[i]);
      if (ch[u][c]==0)
      {
        val[sz]=0;
        memset(ch[sz],0,sizeof ch[sz]);
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
    last[0]=0;
    for (int c=0;c<maxm;c++)
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
      for (int c=0;c<maxm;c++)
      {
        int u=ch[x][c];
        if (u==0)
        {
          ch[x][c]=ch[nex[x]][c];
          continue;
        }
        q[++r]=u;
        int j=nex[x];
        nex[u]=ch[j][c];
        last[u]=val[nex[u]]>0?nex[u]:last[nex[u]];
      }
    }
  }

  void calc(int j)
  {
    if (j!=0)
    {
      cnt++;
      found[val[j]]=true;
      calc(last[j]);
    }
  }

  void find(const char *T)
  {
    cnt=0;
    memset(found,0,sizeof found);

    for (int i=0,j=0;T[i]!='\0';i++)
    {
      int c=idx(T[i]);
      j=ch[j][c];
      if (val[j]!=0)
        calc(j);
      else if (last[j]!=0)
        calc(last[j]);
    }
  }
}acauto;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    acauto.clear();

    for (int i=1;i<=n;i++)
    {
      scanf("%s",P);
      acauto.insert(P,i);
    }

    acauto.get_fail();

    int m;
    scanf("%d",&m);

    int cnt=0;

    for (int i=1;i<=m;i++)
    {
      scanf("%s",T);
      acauto.find(T);

      if (acauto.cnt>0)
      {
        cnt++;
        printf("web %d:",i);
        for (int j=1;j<=n;j++)
          if (found[j])
            printf(" %d",j);
        putchar('\n');
      }
    }

    printf("total: %d\n",cnt);
  }

  return 0;
}
