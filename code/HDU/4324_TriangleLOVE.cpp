/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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

#define maxm 2000000
#define maxn 2007

using namespace std;

int fir[maxn],deg[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int n;

void
add_edge(int _u,int _v)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int st[maxn];

bool
topo_sort()
{
  int top=-1;
  for (int i=0;i<n;i++)
    if (deg[i]==0) st[++top]=i;
  
  for (int i=0;i<n;i++)
  {
    if (top==-1) return false;
    int x=st[top--];
    for (int e=fir[x];~e;e=nex[e])
      if (--deg[v[e]]==0) st[++top]=v[e];
  }
  
  return true;
}

char str[maxn];

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T,__=0;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    scanf("%d",&n);
    
    e_max=0;
    memset(fir,-1,sizeof fir);  
    memset(deg,0,sizeof deg);
    
    for (int i=0;i<n;i++)
    {
      scanf("%s",str);
      for (int j=0;j<n;j++)
      {
        if (str[j]=='1')
        {
          add_edge(i,j);
          deg[j]++;
        }
      }
    }
    
    printf("Case #%d: ",++__);
    if (topo_sort())
      puts("No");
    else
      puts("Yes");
    
  }
  
  return 0;
}



