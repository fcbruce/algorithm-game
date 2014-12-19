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
#define mm

using namespace std;

int g[1001][1001];
itn v[1001];
int cost[1001];
int n,m;
int x,y;
int ans;

itn f()
{
    int MIN=INF,x=-1;
    for (itn i=1;i<=n;i++)
    {
        if (cost[i]!=-1 && MIN>cost[i])
        {
            MIN=cost[i];
            x=i;
        }
    }
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d",&n,&m);
    for (itn i=1;i<=n;i++)
        scanf("%d",v+i);
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        g[x][y]=g[y][x]=1;
        cost[x]+=v[y];
        cost[y]+=v[x];

    }

    for (int i=0;i<n;i++)
    {
        int d=f();
        ans+=cost[d];
        for (itn j=1;j<n;j++)
        {
            if (g[j][d] && cost[j]!=-1)
            {
                cost[j]-=v[d];
            }
        }
        printf("d=%d cost=%d\n",d,cost[d]);
        cost[d]=-1;
        printf("%d\n",ans);
    }

    printf("%d\n",ans);



    return 0;
}
