/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 02 Mar 2015 06:48:30 PM CST
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
#define maxn 

using namespace std;

char buff[233];
char type_[3];

bool vis[64];
bool G[64][64];
int d[64];

int q[233];

inline void add_edge(int u,int v)
{
  if (G[u][v]) return ;
  G[u][v]=true;
  d[v]++;
  vis[u]=vis[v]=true;
}

bool topo()
{
  int cnt=0;
  int f=0,r=-1;
  for (int i=0;i<64;i++) if (vis[i])
  {
    cnt++;
    if (d[i]==0) q[++r]=i;
  }

  for (int i=0;i<cnt;i++)
  {
    if (r<f) return false;
    int x=q[f++];
    for (int i=0;i<64;i++) if (G[x][i])
    {
      d[i]--;
      if (d[i]==0) q[++r]=i;
    }
  }

  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d",&n)==1)
  {
    memset(G,0,sizeof G);
    memset(vis,0,sizeof vis);
    memset(d,0,sizeof d);

    for (int i=0;i<n;i++)
    {
      scanf("%s",buff);
      for (int i=0;i<4;i++) if (buff[i*2]!='0') for (int j=i+1;j<4;j++) if (buff[j*2]!='0')
      {
        int u=buff[i*2]-'A';
        int v=buff[j*2]-'A';
        u<<=1;v<<=1;
        if (buff[i*2+1]=='+') u++;
        if (buff[j*2+1]=='+') v++;

        add_edge(u^1,v);
        add_edge(v^1,u);
      }
    }

    puts(!topo()?"unbounded":"bounded");
  }

  return 0;
}
