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
#define maxm 1000007
#define maxn 1007

using namespace std;

int fir[maxn<<1];
int u[maxm<<2],v[maxm<<2],nex[maxm<<2];
int n,m,e_max;

int pre[maxn<<1],low[maxm<<1],sccno[maxn];
int dfs_clock,scc_cnt;
int st[maxn<<1],top;

inline void add_edge(int _u,int _v)
{
    e_max++;
    u[e_max]=_u;v[e_max]=_v;nex[e_max]=fir[_u];fir[_u]=e_max;
}

void read_graph()
{
    int _u,_v,TF;
    char op[10];
    memset(fir,-1,sizeof fir);
    e_max=-1;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d %s",&_u,&_v,&TF,op);
        if (op[0]=='A')
        {
            if (TF)
            {
                add_edge(_u<<1,_u<<1|1);
                add_edge(_v<<1,_v<<1|1);
            }
            else
            {
                add_edge(_u<<1|1,_v<<1);
                add_edge(_v<<1|1,_u<<1);
            }
            continue;
        }
        if (op[0]=='O')
        {
            if (TF)
            {
                add_edge(_u<<1,_v<<1|1);
                add_edge(_v<<1,_u<<1|1);
            }
            else
            {
                add_edge(_u<<1|1,_u<<1);
                add_edge(_v<<1|1,_v<<1);
            }
            continue;
        }
        if (op[0]=='X')
        {
            if (TF)
            {
                add_edge(_u<<1|1,_v<<1);
                add_edge(_u<<1,_v<<1|1);
                add_edge(_v<<1|1,_u<<1);
                add_edge(_v<<1,_u<<1|1);
            }
            else
            {
                add_edge(_u<<1,_v<<1);
                add_edge(_v<<1,_u<<1);
                add_edge(_u<<1|1,_v<<1|1);
                add_edge(_v<<1|1,_u<<1|1);
            }
            continue;
        }
    }
}

void tarjan_dfs(int _u)
{
    pre[_u]=low[_u]=++dfs_clock;
    st[++top]=_u;
    for (int e=fir[_u];~e;e=nex[e])
    {
        int _v=v[e];
        if (!pre[_v])
        {
            tarjan_dfs(_v);
            low[_u]=min(low[_u],low[_v]);
        }
        else
        {
            if (!sccno[_v])
            {
                low[_u]=min(low[_u],pre[_v]);
            }
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
    memset(pre,0,sizeof pre);
    memset(sccno,0,sizeof sccno);
    dfs_clock=scc_cnt=0;
    top=-1;
    for (itn i=0;i<(n<<1);i++)
        if (!pre[i])
            tarjan_dfs(i);
}

bool check()
{
    for (itn i=0;i<n;i++)
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

    while (~scanf("%d%d",&n,&m))
    {
        read_graph();

        find_scc();

        if (check())
            puts("YES");
        else
            puts("NO");
    }



    return 0;
}
