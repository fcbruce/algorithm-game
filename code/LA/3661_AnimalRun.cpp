/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 14 Oct 2014 11:06:46 PM CST
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

#define maxn 1007
#define maxm 12000007

using namespace std;

int n,m;
int hp[maxn][maxn],vp[maxn][maxn],dp[maxn][maxn];
// hp 0~n*m         vp n*m~n*m*2  dp n*m*2~n*m*3

int fir[maxm];
int u[maxm],v[maxm],w[maxm],nex[maxm];
long long d[maxm];
int e_max;

struct Heap_node
{
    int s;
    long long d;
    bool operator < (const Heap_node &_)const
    {
        return d>_.d;
    }
};

inline void add_edge(int s,int t,int c)
{
//    printf("%d %d %d\n",s,t,c);
    int e=e_max++;
    u[e]=s;v[e]=t;w[e]=c;
    nex[e]=fir[u[e]];fir[u[e]]=e;
//    e=e_max++;
//    u[e]=t;v[e]=s;w[e]=c;
//    nex[e]=fir[u[e]];fir[u[e]]=e;
}

inline int id(int i,int j,int c)
{
  return i*m+j+c*n*m;
}

void build(int s,int t)
{
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0;i<n;i++)
    {
        if (i>0)//up
        {
            for (int j=0;j<m-1;j++)
            {
                add_edge(id(i,j,0),id(i-1,j,2),dp[i-1][j]);//hp-dp
                add_edge(id(i-1,j,2),id(i,j,0),hp[i][j]);

                add_edge(id(i,j,0),id(i-1,j,1),vp[i-1][j]);//hp-vp
                add_edge(id(i-1,j,1),id(i,j,0),hp[i][j]);

                add_edge(id(i-1,j,1),id(i-1,j,2),dp[i-1][j]);//vp-dp
                add_edge(id(i-1,j,2),id(i-1,j,1),vp[i-1][j]);
            }
        }

        if (i<n-1)//down
        {
            for (int j=0;j<m-1;j++)
            {
                add_edge(id(i,j,0),id(i,j,2),dp[i][j]);//hp-dp
                add_edge(id(i,j,2),id(i,j,0),hp[i][j]);

                add_edge(id(i,j,0),id(i,j+1,1),vp[i][j+1]);//hp-vp
                add_edge(id(i,j+1,1),id(i,j,0),hp[i][j]);

                add_edge(id(i,j+1,1),id(i,j,2),dp[i][j]);//vp-dp
                add_edge(id(i,j,2),id(i,j+1,1),vp[i][j+1]);
            }
        }
    }

    for (int i=0;i<m-1;i++)
    {
//        add_edge(i,t,hp[0][i]);//hp-t
        add_edge(id(0,i,0),t,0);
        add_edge(s,id(n-1,i,0),hp[n-1][i]);//s-hp
//        add_edge(s,(n-1)*m+i,0);
    }

    for (int i=0;i<n-1;i++)
    {
        add_edge(s,id(i,0,1),vp[i][0]);//s-vp
//        add_edge(s,n*m+i*m,0);
//        add_edge(n*m+i*m+m-1,t,vp[i][m-1]);//vp-t
        add_edge(id(i,m-1,1),t,0);
    }
}

priority_queue<Heap_node> q;

void dijkstra(int s)
{
    while (!q.empty()) q.pop();
    memset(d,0x3f,sizeof d);

    d[s]=0;
    q.push((Heap_node){s,d[s]});

    while (!q.empty())
    {
        Heap_node x=q.top();q.pop();

        if (d[x.s]<x.d) continue;

        for (int e=fir[x.s];~e;e=nex[e])
        {
            if (d[v[e]]>d[x.s]+w[e])
            {
                d[v[e]]=d[x.s]+w[e];
                q.push((Heap_node){v[e],d[v[e]]});
            }
        }
    }
}

//bool inq[maxm];
//
//void SPFA(int s)
//{
//    queue<int> q;
//
//    memset(inq,0,sizeof inq);
//    memset(d,0x3f,sizeof d);
//
//    d[s]=0;
//    q.push(s);
//
//    while (!q.empty())
//    {
//        int x=q.front();q.pop();
//        inq[x]=false;
//        for (int e=fir[x];~e;e=nex[e])
//        {
//            if (d[v[e]]>d[x]+w[e])
//            {
//                d[v[e]]=d[x]+w[e];
//                if (!inq[v[e]])
//                {
//                    q.push(v[e]);
//                    inq[v[e]]=true;
//                }
//            }
//        }
//    }
//}


int main()
{

#ifdef FCBRUCE
   freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
    int __=0;

    while (scanf("%d%d",&n,&m),n&&m)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<m-1;j++)
//                hp[i][j]=1000000;
                scanf("%d",&hp[i][j]);

        for (int i=0;i<n-1;i++)
            for (int j=0;j<m;j++)
//                vp[i][j]=1000000;
                scanf("%d",&vp[i][j]);

        for (int i=0;i<n-1;i++)
            for (int j=0;j<m-1;j++)
//                dp[i][j]=1000000;
                scanf("%d",&dp[i][j]);

        int s=n*m*3+10,t=s+1;

        build(s,t);

        dijkstra(s);

        printf("Case %d: Minimum = %lld\n",++__,d[t]);
    }

   return 0;
}
