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
#define maxn 10007

using namespace std;

struct EDGE
{
    int xl,xr,y,v;
    void _set(int a,int b,int h,int val)
    {
        xl=a;xr=b;y=h;v=val;
    }
    bool operator < (const EDGE &e)const
    {
        return y<e.y;
    }
}edge[maxn];

int X[maxn<<2];
int sum[maxn<<2],val[maxn<<2],lb[maxn<<2],rb[maxn<<2],_b[maxn<<2];

inline void pushup(int k,int l,int r)
{
    if (val[k])
    {
        sum[k]=X[r]-X[l];
        lb[k]=rb[k]=1;
        _b[k]=2;
    }
    else
    {
        if (r-l==1)
        {
            sum[k]=lb[k]=rb[k]=_b[k]=0;
        }
        else
        {
            sum[k]=sum[k*2+1]+sum[k*2+2];
            _b[k]=_b[k*2+1]+_b[k*2+2];
            if (rb[k*2+1] && lb[k*2+2]) _b[k]-=2;
            lb[k]=lb[k*2+1];rb[k]=rb[k*2+2];
        }
    }
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        val[k]+=v;
        pushup(k,l,r);
    }
    else
    {
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
        pushup(k,l,r);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,x1,x2,y1,y2;

    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            edge[i]._set(x1,x2,y1,1);
            edge[i+n]._set(x1,x2,y2,-1);
            X[i]=x1;
            X[i+n]=x2;
        }
        n<<=1;
        sort(edge,edge+n);
        sort(X,X+n);
        int xn=unique(X,X+n)-X;

        int last_b=0,last_sum=0,ans=0;
        for (int i=0;i<n;i++)
        {
            int a=lower_bound(X,X+xn,edge[i].xl)-X;
            int b=lower_bound(X,X+xn,edge[i].xr)-X;
            update(a,b,edge[i].v,0,0,maxn);
            ans+=abs(last_sum-sum[0]);
            if (i)  ans+=last_b*(edge[i].y-edge[i-1].y);
            last_sum=sum[0];
            last_b=_b[0];
        }

        printf("%d\n",ans);

    }

    return 0;
}
