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
#define mm 40004

using namespace std;

struct point
{
    int x,y;
}pp[202];

int fir[202];
itn u[mm],v[mm],nex[mm];
double w[mm];
double d[202];
bool inq[202];
int q[mm<<2];
int e_c;
int n,f,r;

void SPFA(int _u)
{
    memset(inq,0,sizeof inq);
    for (itn i=1;i<=n;i++)
        d[i]=100000000;
    f=0;r=-1;
    q[++r]=_u;
    d[_u]=0;
//    printf("d[%d]=%.3f\n",_u,d[_u]);
    inq[_u]=true;
    while (f<=r)
    {
        itn x=q[f++];
        inq[x]=false;
        for (int e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]>max(d[u[e]],w[e]))
            {
//                printf("d[%d]=%.3f  ----->    ",u[e],d[u[e]]);
                d[v[e]]=max(d[u[e]],w[e]);
//                printf("d[%d]=%.3f\n",v[e],d[v[e]]);
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                }
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T=0;

    while (scanf("%d",&n),n)
    {
        e_c=-1;
        memset(fir,-1,sizeof fir);
        for (int i=1;i<=n;i++)
        {
            scanf("%d %d",&pp[i].x,&pp[i].y);
            for (itn j=1;j<i;j++)
            {
                ++e_c;
                u[e_c]=i;v[e_c]=j;
                w[e_c]=sqrt((double)sqr(pp[i].x-pp[j].x)+sqr(pp[i].y-pp[j].y));
                nex[e_c]=fir[i];
                fir[i]=e_c;
//                printf("%d %d %.3f\n",u[e_c],v[e_c],w[e_c]);
                e_c++;
                u[e_c]=j;v[e_c]=i;
                w[e_c]=sqrt((double)sqr(pp[i].x-pp[j].x)+sqr(pp[i].y-pp[j].y));
                nex[e_c]=fir[j];
                fir[j]=e_c;
//                printf("%d %d %.3f\n",u[e_c],v[e_c],w[e_c]);
            }
        }

        SPFA(1);
        printf("Scenario #%d\n",++T_T);
        printf("Frog Distance = %.3f\n\n",d[2]);
    }


    return 0;
}
