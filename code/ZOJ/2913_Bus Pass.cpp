#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define maxm 111111
#define maxn 11111

using namespace std;

int hash_to[maxn],hash_back[maxn];
bool vis[maxn];
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
int res[maxn],dis[maxn];
int q[maxn];

void add_edge(int _u,int _v)
{
    int e=e_max++;
    u[e]=_u;v[e]=_v;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void bfs(int s)
{
    memset(dis,0,sizeof dis);
    int f,r;
    q[f=r=0]=s;
    dis[s]=1;
    res[s]=max(res[s],dis[s]);
    while (f<=r)
    {
        int x=q[f++];
        for (int e=fir[x];~e;e=nex[e])
        {
            if (!dis[v[e]])
            {
                dis[v[e]]=dis[x]+1;
                res[v[e]]=max(res[v[e]],dis[v[e]]);
                q[++r]=v[e];
            }
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,m;
    scanf("%d",&T_T);

    while (T_T--)
    {
        scanf("%d %d",&n,&m);
        memset(hash_to,-1,sizeof hash_to);
        memset(vis,0,sizeof vis);
        memset(fir,-1,sizeof fir);
        memset(res,0,sizeof res);
        e_max=0;

        int _u,_v,k,cnt=0;

        for (int i=0;i<n;i++)
        {
            scanf("%d",&_u);
            if (hash_to[_u]==-1) hash_to[_u]=cnt++,hash_back[hash_to[_u]]=_u;
            _u=hash_to[_u];
            scanf("%d",&k);
            for (int j=0;j<k;j++)
            {
                scanf("%d",&_v);
                if (hash_to[_v]==-1) hash_to[_v]=cnt++,hash_back[hash_to[_v]]=_v;
                _v=hash_to[_v];
                add_edge(_u,_v);
            }
        }

        for (int i=0;i<m;i++)
        {
            scanf("%d",&k);
            for (int j=0;j<k;j++)
            {
                scanf("%d",&_u);
                _u=hash_to[_u];
                if (!vis[_u])   bfs(_u);
                vis[_u]=true;
            }
        }

        int MIN=INF,id=-1;
        for (int i=0;i<n;i++)
            if (id==-1 || MIN>res[i] || MIN==res[i] && hash_back[i]<id)
            {
                id=hash_back[i];
                MIN=res[i];
            }

        printf("%d %d\n",MIN,id);
    }

    return 0;
}
