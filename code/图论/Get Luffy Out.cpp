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
#define maxm 1<<11<<2
#define maxn 1<<10<<2

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int n,m,e_max;

struct Door
{
    int x,y;
}door[maxm>>1];

struct key
{
    int x,y;
}key[maxn>>1];

void init(int mid)
{
    e_max=-1;
    memset(fir,-1,sizeof fir);
    for (itn i=0;i<n;i++)
    {
        e_max++;
        u[e_max]=key[i].x<<1|1;v[e_max]=key[i].y<<1;nex[e_max]=fir[key[i].x<<1|1];fir[key[i].x<<1|1]=e_max;
        e_max++;
        u[e_max]=key[i].y<<1|1;v[e_max]=key[i].x<<1;nex[e_max]=fir[key[i].y<<1|1];fir[key[i].y<<1|1]=e_max;
    }
    for (int i=0;i<mid;i++)
    {
        e_max++;
        u[e_max]=door[i].x<<1;v[e_max]=door[i].y<<1|1;nex[e_max]=fir[door[i].x<<1];fir[door[i].x<<1]=e_max;
        e_max++;
        u[e_max]=door[i].y<<1;v[e_max]=door[i].x<<1|1;nex[e_max]=fir[door[i].y<<1];fir[door[i].y<<1]=e_max;
    }
}

int pre[maxn],low[maxn],sccno[maxn];
int dfs_clock,scc_cnt;
int st[maxn],top;

void tarjan_dfs(int _u)
{
    pre[_u]=low[_u]=++dfs_clock;
    st[++top]=_u;
    for (int e=fir[_u];~e;e=nex[e])
    {
        if (!pre[v[e]])
        {
            tarjan_dfs(v[e]);
            low[_u]=min(low[_u],low[v[e]]);
        }
        else
        {
            if (!sccno[v[e]])
                low[_u]=min(low[_u],pre[v[e]]);
        }
    }

    if (low[_u]==pre[_u])
    {
        scc_cnt++;
        while (true)
        {
            int x=st[top--];
            sccno[x]=scc_cnt;
            if (x==_u)  break;
        }
    }
}

void find_scc()
{
    memset(sccno,0,sizeof sccno);
    memset(pre,0,sizeof pre);
    dfs_clock=scc_cnt=0;
    top=-1;
    for (int i=0;i<(n<<1);i++)
    {
        if (!pre[i])
            tarjan_dfs(i);
    }
}

bool check()
{
    for (int i=0;i<n;i++)
    {
        if (sccno[i<<1]==sccno[i<<1|1]) return false;
    }

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d %d",&n,&m),n||m)
    {
        e_max=-1;
        int x,y;
        memset(fir,-1,sizeof fir);
        for (int i=0;i<n;i++)
        {
            scanf("%d %d",&key[i].x,&key[i].y);
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&door[i].x,&door[i].y);
        }

        int l,r,ans;
        l=0;r=m;
        while (l<=r)
        {
            int mid=l+r>>1;
            init(mid);
            find_scc();
            if (check())
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
