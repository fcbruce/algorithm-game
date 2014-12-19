/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-19 23:25:40 
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

#define maxm 2555
#define maxn 1007

using namespace std;

bool vis[maxn];
int milk[maxn][maxm];
int t[maxn];

inline int
lcm(int x,int y)
{
  return x*y/__gcd(x,y);
}

int
main()
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
    for (int i=0;i<n;i++)
    {
      scanf("%d",t+i);
      for (int j=0;j<t[i];j++)
        scanf("%d",&milk[i][j]);
    }
    
    int T=1;
    for (int i=0;i<n;i++)
      T=lcm(T,t[i]);
      
    for (int i=0;i<n;i++)
    {
      int times=T/t[i];
      for (int j=1;j<times;j++) memcpy(milk[i]+j*t[i],milk[i],t[i]*sizeof(int));
    }
    
    memset(vis,0,sizeof vis);
    
    int rest=n,last_rest=0;
    int pass_day=-1;
    
    for (int i=0,day=0;;i++,day++)
    {
      if (i==T)
      {
        if (last_rest==rest) break;
        last_rest=rest;
        i=0;
      }
      if (rest==0) break;
      
      int v=-1,cnt;
      for (int j=0;j<n;j++)
        if (!vis[j] && (v==-1 || milk[j][i]<milk[v][i])) v=j,cnt=1;
        else if (!vis[j] && v!=-1 && milk[j][i]==milk[v][i]) cnt++;
      
      if (cnt>1) continue;
      
      vis[v]=true;
      rest--;
      pass_day=day;
      
    }
    
    printf("%d %d\n",rest,pass_day+1);
    
  }
  
  return 0;
}



