/*
 *
 * Author : fcbruce
 *
 * Time : Sat 04 Oct 2014 07:11:14 PM CST
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

#define maxm 500007
#define maxn 26

using namespace std;

int q[maxm<<2];

struct ACauto
{
  int ch[maxm][maxn];
  int val[maxm];
  int nex[maxm];
  int last[maxm];
  int cnt;
  int sz;

  ACauto()
  {
    cnt=0;
    sz=1;
    memset(ch[0],0,sizeof ch[0]);
  }

  void clear()
  {
    cnt=0;
    sz=1;
    memset(ch[0],0,sizeof ch[0]);
  }

  int idx(const char ch)
  {
    return ch-'a';
  }

  void insert(const char *s)
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
    val[u]++;
  }

  void calc(int j)
  {
    if (j!=0)
    {
      cnt+=val[j];
      val[j]=0;
      calc(last[j]);
    }
  }

  void get_fail()
  {
    int f=0,r=-1;
    nex[0]=0;
    for (int i=0;i<maxn;i++)
    {
      int u=ch[0][i];
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
      for (int i=0;i<maxn;i++)
      {
        int u=ch[x][i];
        if (u==0) continue;
        q[++r]=u;
        int j=nex[x];
        while (j>0 && ch[j][i]==0) j=nex[j];
        nex[u]=ch[j][i];
        last[u]=val[nex[u]]>0?nex[u]:last[nex[u]];
      }
    }
  }

  void find(const char *T)
  {
    for (int i=0,j=0;T[i]!='\0';i++)
    {
      int c=idx(T[i]);
      while (j>0 && ch[j][c]==0) j=nex[j];
      j=ch[j][c];
      if (val[j]!=0)
        calc(j);
      else if (last[j]!=0)
        calc(last[j]);
    }
  }
}acauto;

char word[55];
char T[1000007];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d\n",&T_T);

  while (T_T--)
  {
    acauto.clear();

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
      scanf("%s",&word);
      acauto.insert(word);
    }

    acauto.get_fail();

    scanf("%s",T);
    acauto.find(T);

    printf("%d\n",acauto.cnt);
  }

  return 0;
}
