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
#define maxn

using namespace std;

struct node
{
    int k,n,t,id;
    bool operator < (const node &n)const
    {
        if (t==n.t)return id<n.id;
        return t<n.t;
    }
}a[1007];
int rec[1007];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,k,t,m,s1,m1;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d %d %d %d",&n,&t,&k,&m);
        memset(rec,0,sizeof rec);

        for (int i=0;i<m;i++)
        {
            scanf("%d:%d",&s1,&m1);
            a[i].t=s1*60+m1;
            scanf("%d %d",&a[i].k,&a[i].n);
        }

        sort(a,a+m);
        int now=0;

        for  (itn i=0;i<m;i++)
        {
            if (rec[a[i].k]<a[i].n)
            {
                int need=a[i].n-rec[a[i].k];
                int time=ceil((double)need/k)*t;
                now=max(now,a[i].t);
                if (i+1<m && a[i+1].t<=now)
                    rec[a[i].k]+=ceil((double)need/k)*k;
                else
                    rec[a[i].k]=a[i].n;
                now+=time;
                printf("%02d:%02d\n",now/60,now%60);
            }
            else
            {
                now=max(now,a[i].t);
                printf("%02d:%02d\n",now/60,now%60);
            }
            rec[a[i].k]-=a[i].n;
        }

        if (T_T)puts("");
    }


    return 0;
}
