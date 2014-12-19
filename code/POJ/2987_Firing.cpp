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
#define maxm 70000
#define maxn 5007

using namespace std;

int fir[maxn];
int u[maxm],v[maxn],num[maxn],nex[maxn];
bool vis[maxn];
long long w[maxn];
int e_max;
int deg[maxn];

pair<long long ,int> dfs(int _u)
{
    pair<long long ,int> p1,p2();
    vis[_u]=true;
    for (int e=fir[_u];~e;e=nex[e])
    {
        if (!vis[v[e]])
        {
            p1=dfs(v[e]);
            p2.first+=p1.first;
            p2.second+=p1.second;
            p1=pair<long long ,int>(0,0);
        }
        w[u[e]]+=w[v[e]];
        num[u[e]]+=num[v[e]];
    }

    return p2;


}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",w+i);
        num[i]=1;
    }
    memset(deg,0,sizeof deg);
    memset(fir,-1,sizeof fir);
    e_max=0;
    for (int i=0;i<m;i++)
    {
        int e=e_max++;
        scanf("%d %d",u+e,v+e);
        printf("%d --> %d\n",u[e],v[e]);
        nex[e]=fir[u[e]];
        fir[u[e]]=e;
        deg[v[e]]++;
    }

    memset(vis,0,sizeof vis);

    for (int i=1;i<=n;i++)
    {
        if (deg[i]==0)
        {
            dfs(i);
        }
    }

    int MAX=1;
    for (int i=1;i<=n;i++)
    {
        printf("%d %d\n",num[i],w[i]);
        if (w[MAX]<w[i])
        {
            MAX=i;
        }
        if (w[MAX]==w[i] && num[MAX]>num[i])
        {
            MAX=i;
        }
    }

    printf("%d %lld",num[MAX],w[MAX]);

    return 0;
}
