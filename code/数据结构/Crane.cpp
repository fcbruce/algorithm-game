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

int L[maxn];
double last[maxn],ang[maxn<<2],vx[maxn<<2],vy[maxn<<2];

void build(int k,int l,int r)
{
    ang[k]=vx[k]=0;
    if (r-l==1)
    {
        vy[k]=L[l];
    }
    else
    {
        build(k*2+1,l,l+r>>1);
        build(k*2+2,l+r>>1,r);
        vy[k]=vy[k*2+1]+vy[k*2+2];
    }
}

void update(int s,double a,int k,int l,int r)
{
    if (s<=l)   return ;
    else    if(s<r)
    {
        int m=l+r>>1;
        update(s,a,k*2+1,l,m);
        update(s,a,k*2+2,m,r);

        if (s<=m)   ang[k]+=a;

        double _cos=cos(ang[k]),_sin=sin(ang[k]);
        vx[k]=vx[k*2+1]+_cos*vx[k*2+2]-_sin*vy[k*2+2];
        vy[k]=vy[k*2+1]+_sin*vx[k*2+2]+_cos*vy[k*2+2];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,c,s;
    double a;
    bool flag=false;

    while (scanf("%d %d",&n,&c)==2)
    {
        if (flag)   puts("");
        flag=true;
//        scanf("%d %d",&n,&c)
//        L[0]=0;last[0]=PI;

        for (int i=0;i<n;i++)
        {
            scanf("%d",L+i);
            last[i]=PI;
        }
        build(0,0,n);

        for (int i=0;i<c;i++)
        {
            scanf("%d %lf",&s,&a);
            a=a/360*2*PI;
            update(s,a-last[s],0,0,n);
            last[s]=a;

            printf("%.2f %.2f\n",vx[0],vy[0]);
        }


    }

    return 0;
}
