/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 06 May 2015 06:17:29 PM CST
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

#define maxm 2333
#define maxn 32

using namespace std;

int n,m;
char s[233];

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int q[maxn];
int d[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int topo[233];
int ind[maxn];

int toposort()
{
  int f=0,r=-1;
  memcpy(d,ind,sizeof d);

  for (int i=0;i<n;i++)
    if (d[i]==0) q[++r]=i;

  bool mult=false;

  for (int i=0;i<n;i++)
  {
    if (r<0) return -1;
    if (r>0) mult=true;

    int x=q[r--];

    topo[i]=x;
    for (int e=fir[x];~e;e=nex[e])
    {
      d[v[e]]--;
      if (d[v[e]]==0) q[++r]=v[e];
    }
  }

  if (mult) return 0;
  return 1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  while (scanf("%d %d",&n,&m),n||m)
  {
    memset(fir,-1,sizeof fir);
    e_max=0;

    memset(ind,0,sizeof ind);

    int res=0;
    int ok=-1;
    for (int i=0;i<m;i++)
    {
      scanf("%s",s);
      int u=s[0]-'A',v=s[2]-'A';

      add_edge(u,v);
      ind[v]++;

      if (res!=0) continue;

      res=toposort();
      if (res!=0) ok=i+1;
    }

    if (res==0) puts("Sorted sequence cannot be determined.");
    else if (res==-1) printf("Inconsistency found after %d relations.\n",ok);
    else
    {
      printf("Sorted sequence determined after %d relations: ",ok);
      for (int i=0;i<n;i++) putchar('A'+topo[i]);
      puts(".");
    }
  }



  return 0;
}
