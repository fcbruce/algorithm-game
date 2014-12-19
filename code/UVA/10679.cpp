/*
 *
 * Author : fcbruce
 *
 * Time : Sat 04 Oct 2014 03:30:15 PM CST
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
#define maxsize 52

using namespace std;

int q[maxn<<1];
int _id[1007];
char YN[1007];
char query[1007];
char T[maxn];

struct Trie
{
  int ch[maxn][maxsize];
  int val[maxn];
  int sz;
  Trie()
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
    if (islower(ch)) return ch-'a'+26;
    return ch-'A';
  }

  int insert(const char *s,int v=1)
  {
    int u=0,l=strlen(s);
    for (int i=0;i<l;i++)
    {
      int c=idx(s[i]);
      if (ch[u][c]==0)
      {
        val[sz]=0;
        memset(ch[sz],0,sizeof ch[0]);
        ch[u][c]=sz++;
      }
      u=ch[u][c];
    }

    if (val[u]!=0) return val[u];
    return val[u]=v;
  }
};

struct ACauto :public Trie
{
  int cnt;
  int last[maxn];
  int nex[maxn];

  ACauto()
  {
    cnt=0;
    sz=1;
    val[0]=0;
    memset(ch[0],0,sizeof ch[0]);
  }
  void clear()
  {
    cnt=0;
    sz=1;
    val[0]=0;
    memset(ch[0],0,sizeof ch[0]);
  }

  void calc(int j)
  {
    if (j!=0)
    {
      YN[val[j]]='y';
      calc(last[j]);
    }
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
        last[u]=val[nex[u]]>0?nex[u]:last[nex[u]];
      }
    }
  }

  void find(const char *T)
  {
    get_fail();
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

  int T_T;
  scanf ("%d",&T_T);

  while (T_T--)
  {
    acauto.clear();
    scanf("%s",T);

    int n;
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
    {
      scanf("%s",query);
      _id[i]=acauto.insert(query,i);
      YN[i]='n';
    }

    acauto.find(T);

    for (int i=1;i<=n;i++)
      printf("%c\n",YN[_id[i]]);
  }


  return 0;
}
