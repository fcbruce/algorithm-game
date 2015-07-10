/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 09 Jul 2015 07:41:24 PM CST
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
#define maxn (1<<19)

using namespace std;

int win[maxn];

void dfs(int status)
{
  if (win[status]!=-1) return ;
  win[status]=0;
  if (status==0) return ;
  for (int i=2;i<=20;i++) if ((status&(1<<i-2))!=0)
  {
    int s=status;
    for (int j=20;j>1;j--) if ((status&(1<<j-2))==0)
    {
      for (int k=1;k*j+i<=20;k++)
      {
        int l=1;
        while (k*j+i*l<=20) 
        {
          s&=~(1<<(k*j+i*l-2));
          l++;
        }
      }
    }

    int l=1;
    while (i*l<=20) 
    {
      s&=~(1<<(i*l-2));
      l++;
    }
    dfs(s);
    if (!win[s])
    {
      win[status]|=1<<i-2;
    }
  }
}

void init()
{
  int status=0x001ffffc;
  status>>=2;
  
  dfs(status);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(win,-1,sizeof win);
  init();

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    printf("Scenario #%d:\n",++__);
    int n,status=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
      int k;
      scanf("%d",&k);
      status|=1<<k-2;
    }

    if (win[status])
    {
      printf("The winning moves are:");
      for (int i=2;i<=20;i++)
      {
        if ((win[status]&(1<<i-2))!=0) printf(" %d",i);
      }
      puts(".");
    }
    else
    {
      puts("There is no winning move.");
    }
    puts("");
  }

  return 0;
}
