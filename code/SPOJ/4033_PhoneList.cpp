/*
 *
 * Author : fcbruce
 *
 * Time : Sat 04 Oct 2014 02:24:12 PM CST
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
#define maxn 100007
#define maxsize 10

using namespace std;

int q[maxn];

struct Trie
{
  int ch[maxn][maxsize];
  int val[maxn];
  int sz;
  Trie()
  {
    sz=1;
    val[0]=-1;
    memset(ch[0],0,sizeof ch[0]);
  }
  int idx(const char ch)
  {
    return ch-'0';
  }
  void clear()
  {
    sz=1;
    val[0]=-1;
    memset(ch[0],0,sizeof ch[0]);
  }
  
  bool insert(const char *s)
  {
    int u=0,l=strlen(s);
    for (int i=0;i<l;i++)
    {
      int c=idx(s[i]);
      if (ch[u][c]==0)
      {
        memset(ch[sz],0,sizeof ch[sz]);
        val[sz]=-1;
        ch[u][c]=sz++;
      }
      u=ch[u][c];
      if (val[u]!=-1) return false;
    }

    val[u]=1;
    return true;
  }

  bool check()
  {
    int f,r;
    q[f=r=0]=0;

    while (f<=r)
    {
      int x=q[f++];
      bool addq=false;
      for (int i=0;i<maxsize;i++)
      {
        if (ch[x][i]!=0)
        {
          q[++r]=ch[x][i];
          addq=true;
        }
      }

      if (addq && val[x]!=-1) return false;
    }

    return true;
  }

}trie;

char str[20];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);

    trie.clear();

    bool ok=true;

    for (int i=0;i<n;i++)
    {
      scanf("%s",str);
      if (ok) ok=trie.insert(str);
    }

    if (ok && trie.check()) puts("YES");
    else puts("NO");
  }


  return 0;
}
