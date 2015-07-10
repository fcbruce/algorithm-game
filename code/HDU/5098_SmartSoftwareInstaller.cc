/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 05 Jul 2015 08:38:13 AM CST
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

#define maxm 1000007
#define maxn 1007

using namespace std;

map<string,size_t> software;

int fir[maxn],w[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int d[maxn];
bool inq[maxn];
int q[maxm<<3];

char buff[maxn],install[maxn],dep[maxn];

inline int id(char *s)
{
  string tmp(s);
  if (software.count(tmp)==0) 
    return software[tmp]=(int)software.size();
  else
    return software[tmp];
}

inline void reboot(char *s,bool ok)
{
  if (ok)
  {
    s[strlen(s)-2]='\0';
    w[id(s)]=1;
  }
  else
  {
    s[strlen(s)-1]='\0';
    w[id(s)]=0;
  }
}

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA()
{
  int f=0,r=-1;
  memset(inq,true,sizeof inq);
  for (size_t i=1;i<=software.size();i++)
  {
    q[++r]=i;
    d[i]=w[i];
  }

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (d[v[e]]<d[x]+w[v[e]])
      {
        d[v[e]]=d[x]+w[v[e]];
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);gets(buff);

  gets(buff);

  while (T_T--)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    software.clear();

    while (gets(buff)!=NULL && buff[0]!='\0')
    {
      stringstream ss(buff);
      ss>>install;
      int l=strlen(install);
      if (install[l-2]=='*') reboot(install,true);
      else reboot(install,false);

      while (ss>>dep)
        add_edge(id(dep),id(install));
    }

    SPFA();

    int res=0;
    for (size_t i=1;i<=software.size();i++) res=max(res,d[i]);

    printf("Case %d: %d\n",++__,res);
  }



  return 0;
}
