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
#define maxm
#define maxn 8001

using namespace std;

struct _Segment
{
    int x,y1,y2;
    bool operator < (const _Segment &seg)const
    {
        return x<seg.x;
    }
}seg[maxn];

bool G[maxn][maxn];

int col[maxn<<3];

void pushdown(int k)
{
    if (col[k]>0)
    {
        col[k*2+1]=col[k*2+2]=col[k];
        col[k]=-1;
    }
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return;
    if (a<=l && r<=b)
    {
        col[k]=v;
        return ;
    }
    if (r-l==1) return ;
    pushdown(k);
    update(a,b,v,k*2+1,l,l+r>>1);
    update(a,b,v,k*2+2,l+r>>1,r);
}

void query(int a,int b,int v,int k,int l,int r)
{
    if (col[k]>0)
    {
        G[col[k]][v]=true;
        return;
    }
    if (r-l==1) return ;
    int m=l+r>>1;
    pushdown(k);
    if (a<m)   query(a,b,v,k*2+1,l,m);
    if (b>m)   query(a,b,v,k*2+2,m,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n;
    scanf("%d",&T_T);
    while (T_T--)
    {
        memset(col,0,sizeof col);
        memset(G,0,sizeof G);
        scanf("%d",&n);
        for (itn i=0;i<n;i++)
        {
            scanf("%d %d %d",&seg[i].y1,&seg[i].y2,&seg[i].x);
            seg[i].y1<<=1;
            seg[i].y2<<=1;
            seg[i].y2++;
        }

        sort(seg,seg+n);


        for (int i=0;i<n;i++)
        {
            query(seg[i].y1,seg[i].y2,i+1,0,0,maxn<<1);
            update(seg[i].y1,seg[i].y2,i+1,0,0,maxn<<1);
        }

        int ans=0;

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (G[i][j])
                {
                    for (int k=1;k<=n;k++)
                    {
                        if (G[i][k] && G[k][j])
                        {
                            ans++;
                        }
                    }
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
