/*
 *
 *    Author    :    fcbruce
 *
 *    Date    :    2014-09-18 11:47:33  
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

#define maxm 8964
#define maxn 107

using namespace std;

int A,B,M,L,K;
int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max=0;

int dp[maxn][12],shoe[maxn][maxn];
bool inq[maxn];
int q[maxm];


inline void add_edge(int _u,int _v,int _w)
{
    int e=e_max++;
    u[e]=_u;v[e]=_v;w[e]=_w;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void init()
{
    int f,r;
    
    memset(shoe,0x3f,sizeof shoe);
    
    for (int i=1;i<=A+B;i++)
    {
        memset(inq,0,sizeof inq);
        q[f=r=0]=i;
        shoe[i][i]=0;
        
        while (f<=r)
        {
            int x=q[f++];
            inq[x]=false;
            for (int e=fir[x];~e;e=nex[e])
            {
                if (shoe[i][v[e]]>shoe[i][u[e]]+w[e])
                {
                    shoe[i][v[e]]=shoe[i][u[e]]+w[e];
                    if (v[e]<=A && !inq[v[e]])
                    {
                        inq[v[e]]=true;
                        q[++r]=v[e];
                    }
                }
            }
        }
    }
}

void solve(int s)
{
    int f,r;
    memset(inq,0,sizeof inq);
    memset(dp,0x3f,sizeof dp);
    dp[s][0]=0;
    q[f=r=0]=s;
    
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        
        for (int i=0;i<=K;i++)
        {
            for (int e=fir[x];~e;e=nex[e])
            {
                if (dp[v[e]][i]>dp[u[e]][i]+w[e])
                {
                    dp[v[e]][i]=dp[u[e]][i]+w[e];
                    if (!inq[v[e]])
                    {
                        inq[v[e]]=true;
                        q[++r]=v[e];
                    }
                }
            }
            
            if (i==K)   continue;
            
            for (int _v=1;_v<=A+B;_v++)
            {
                if (shoe[x][_v]<=L && dp[_v][i+1]>dp[x][i])
                {
                    dp[_v][i+1]=dp[x][i];
                    if (!inq[_v])
                    {
                        inq[_v]=true;
                        q[++r]=_v;
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

    int T_T;
    
    scanf("%d",&T_T);
    
    while (T_T--)
    {
        scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
        
        e_max=0;
        memset(fir,-1,sizeof fir);
        
        for (int i=0,u,v,w;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        
        init();
        
        solve(A+B);
        
        int MIN=INF;
        
        for (int i=0;i<=K;i++)
            MIN=min(MIN,dp[1][i]);
            
        printf("%d\n",MIN);
    }
    
    return 0;
}



