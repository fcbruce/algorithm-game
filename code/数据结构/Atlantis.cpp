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
#define maxn 202

using namespace std;

struct EDGE
{
    double xl,xr,y;
    int v;
    void _set(double a,double b,double h,int val)
    {
        xl=a;xr=b;y=h;v=val;
    }
    bool operator < (const EDGE &e)const
    {
        return y<e.y;
    }
}edge[maxn];

double X[maxn];
double sum[maxn<<2];
int val[maxn<<2];

inline void pushup(int k,int l,int r)
{
    if (val[k])
        sum[k]=X[r]-X[l];
    else    if (r-l==1)
                sum[k]=0;
            else
                sum[k]=sum[k*2+1]+sum[k*2+2];
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

    int n;
    double x1,x2,y1,y2;
    int m=202;
    int T_T=0;

    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            edge[i]._set(x1,x2,y1,1);
            edge[i+n]._set(x1,x2,y2,-1);
            X[i]=x1;X[i+n]=x2;
        }
        n<<=1;
        sort(edge,edge+n);
        sort(X,X+n);
        int xn=unique(X,X+n)-X;
        double area=0;

        for (int i=0;i<n;i++)
        {
            if (i)  area+=(edge[i].y-edge[i-1].y)*sum[0];
            int a=lower_bound(X,X+xn,edge[i].xl)-X;
            int b=lower_bound(X,X+xn,edge[i].xr)-X;
            int v=edge[i].v;
            update(a,b,v,0,0,m);
        }

        T_T++;
        printf("Test case #%d\n",T_T);
        printf("Total explored area: %.2f\n\n",area);
    }

    return 0;
}
