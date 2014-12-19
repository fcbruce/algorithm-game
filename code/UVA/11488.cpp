/*
 *
 * Author : fcbruce
 *
 * Time : Sat 04 Oct 2014 09:17:50 PM CST
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

#define maxm 2
#define maxn 5000007

using namespace std;

struct Trie
{
  int ch[maxn][maxm];
  int deep[maxn];
  int cnt[maxn][maxm];
  int MAX;
  int sz;

  Trie()
  {
    sz=1;
    deep[0]=0;
    MAX=0;
    memset(cnt[0],0,sizeof cnt[0]);
    memset(ch[0],0,sizeof ch[0]);
  }

  void clear()
  {
    sz=1;
    deep[0]=0;
    MAX=0;
    memset(cnt[0],0,sizeof cnt[0]);
    memset(ch[0],0,sizeof ch[0]);
  }

  int idx(const char ch)
  {
    return ch-'0';
  }

  void insert(const char *s)
  {
    for (int i=0,j=0;s[i]!='\0';i++)
    {
      int c=idx(s[i]);
      if (ch[j][c]==0)
      {
        memset(ch[sz],0,sizeof ch[sz]);
        memset(cnt[sz],0,sizeof cnt[sz]);
        deep[sz]=i+1;
        ch[j][c]=sz++;
      }
      j=ch[j][c];
      cnt[j][c]++;
      MAX=max(MAX,deep[j]*cnt[j][c]);
    }
  }
}trie;

char str[233];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    trie.clear();

    int n;
    scanf("%d",&n);
    
    for (int i=0;i<n;i++)
    {
      scanf("%s",str);
      trie.insert(str);
    }

    printf("%d\n",trie.MAX);
  }


  return 0;
}
