/*
 *
 * Author : fcbruce
 *
 * Time : Sun 05 Oct 2014 06:44:35 PM CST
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
#define maxn 507

using namespace std;

struct _record
{
  int start[24],stop[24],time[24];
  int cnt;
}w[maxm];

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max=0;

int vis[maxn][maxn];
bool go[20];

inline int ReadInt()
{
  int flag=0;
  int data=0;
  char ch=getchar();
  while (ch<'0' || ch>'9')
  {
    if (ch=='-') flag=1;
    ch=getchar();
  }
  do
  {
    data=data*10+ch-'0';
    ch=getchar();
  }while (ch>='0' && ch<='9');
  if (flag) data=-data;
  return data;
}


inline void add_edge(int _u,int _v)
{
  int &e=e_max;
  e++;
  u[e]=_u;v[e]=_v;
  nex[e]=fir[u[e]];fir[u[e]]=e;
  for (int i=0,start,stop=0,time,j=0;stop!=1439;i++)
  {
    start=ReadInt();
    stop=ReadInt();
    time=ReadInt();
    w[e].start[j]=w[e+1].start[j]=start;
    w[e].stop[j]=w[e+1].stop[j]=stop;
    w[e].time[j]=w[e+1].time[j]=time*2;
    w[e].cnt=w[e+1].cnt=++j;
  }
  e++;
  u[e]=_v;v[e]=_u;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

struct Heap_node
{
  int pos,time,power;
  bool operator < (const Heap_node &_)const
  {
    return time>_.time;
  }
};

priority_queue<Heap_node> q;

int bfs(int s,int t,int start)
{
  while (!q.empty()) q.pop();
  memset(vis,0x3f,sizeof vis);
  Heap_node iter=(Heap_node){s,start,480};
  q.push(iter);
  vis[0][480]=720;
  
  while (!q.empty())
  {
    Heap_node x=q.top();q.pop();
    if (x.pos==t) return x.time-start;

    for (int e=fir[x.pos];~e;e=nex[e])
    {
      memset(go,0,sizeof go);
      int begin;
      for (int i=0;i<w[e].cnt;i++)
        if (x.time% 1440>=w[e].start[i] && x.time% 1440<=w[e].stop[i])
        {
          begin=i;
          break;
        }

      if (w[e].time[begin]>480) goto too_far;
      if (x.power>=w[e].time[begin])
      {
        go[begin]=true;
        iter=(Heap_node){v[e],x.time+w[e].time[begin]/2,x.power-w[e].time[begin]};
        if (vis[iter.pos][iter.power]>iter.time)
        {
          q.push(iter);
          vis[iter.pos][iter.power]=iter.time;
        }
      }
      else
      {
        int charge=w[e].time[begin]-x.power;
        if (x.time % 1440+charge<=w[e].stop[begin])
        {
          go[begin]=true;
          iter=(Heap_node){v[e],x.time+charge+w[e].time[begin]/2,0};
          if (vis[iter.pos][iter.power]>iter.time)
          {
            q.push(iter);
            vis[iter.pos][iter.power]=iter.time;
          }
        }
      }
too_far:

      int plus=0;
      for (int j=begin+1;j<w[e].cnt*2+begin+1;j++)
      {
        int i=j%w[e].cnt;
        if (w[e].start[i]==0) plus+=1440;
        if (w[e].time[i]>480) continue;
        if (go[i]) continue;
        int power=x.power;
        int time=w[e].start[i]+plus-x.time% 1440;
        power+=time;
        power=min(480,power);
        if (power>=w[e].time[i])
        {
          go[i]=true;
          iter=(Heap_node){v[e],x.time+time+w[e].time[i]/2,power-w[e].time[i]};
          if (vis[iter.pos][iter.power]>iter.time)
          {
            q.push(iter);
            vis[iter.pos][iter.power]=iter.time;
          }
        }
        else
        {
          int charge=w[e].time[i]-power;
          if (w[e].start[i]+charge<=w[e].stop[i])
          {
            go[i]=true;
            iter=(Heap_node){v[e],x.time+time+charge+w[e].time[i]/2,0};
            if (vis[iter.pos][iter.power]>iter.time)
            {
              q.push(iter);
              vis[iter.pos][iter.power]=iter.time;
            }
          }
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

  int n,m;

  while (scanf("%d%d",&n,&m),n||m)
  {
    memset(fir,-1,sizeof fir);
    e_max=0;

    for (int i=0,u,v;i<m;i++)
    {
     // scanf("%d%d",&u,&v);
      u=ReadInt();v=ReadInt();
      add_edge(u,v);
    }

    printf("%d\n",bfs(0,n-1,720));
  }

  return 0;
}
