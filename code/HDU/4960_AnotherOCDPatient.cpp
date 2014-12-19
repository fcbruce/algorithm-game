#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
#define LL long long
#define INF 0x3f3f3f3f
#define itn int
#define maxn 5007
#define maxm 2333333

const long long INFLL=0x3f3f3f3f3f3f3f3fLL;

using namespace std;
int a[10005];
int c[10005];
long long pref[10005], suff[10005];
int cost[maxn];


int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
long long w[maxm],d[maxn];
int e_max;
int q[maxm<<4];
bool inq[maxn];
int __hash[maxn];

void add_edge(int _u,int _v,int _w)
{

    int e=e_max++;
    u[e]=_u;v[e]=_v;w[e]=_w;
    nex[e]=fir[u[e]];fir[u[e]]=e;

//    printf ("add %d --> %d %d\n",u[e],v[e],w[e]);
}

void SPFA(int s)
{
    int f,r;
    q[f=r=0]=s;
    memset(d,0x3f,sizeof d);
    d[s]=0;
    memset(inq,0,sizeof inq);
    while (f<=r)
    {

        itn x=q[f++];
        inq[x]=false;
        for (int e=fir[x];~e;e=nex[e])
        {
            if (d[v[e]]>d[u[e]]+w[e])
            {
                d[v[e]]=d[u[e]]+w[e];
                if (!inq[v[e]])
                {

                    inq[v[e]]=true;
                    q[++r]=v[e];
                }
            }
        }
    }
}

long long dp[maxn];

int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        e_max=0;
        memset(fir,-1,sizeof fir);
       
        a[0]=a[n+1]=0;
        for (int i=1;i<=n;i++)
            scanf( "%d",a+i);

        pref[0]=0;
        for (int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+a[i];
//            printf ("%d ",pref[i]);

        }

//puts("");
        suff[n+1]=0;
//        MAP[0]=n+1;
        for (int i=n;i>=0;i--)
        {
            suff[i]=suff[i+1]+a[i];
//            MAP[suff[i]]=i;
//             printf ("%d ",suff[i]);
        }
        memset(__hash,-1,sizeof __hash);
        for (int i=0,j=n+1;i<=n && i<=j;i++)
        {
        	while (suff[j]<pref[i])	j--;
        	if (suff[j]==pref[i])
        	{
		    	__hash[i]=j;
		    	j--;
        	}
        }
//puts("");
        for (int i=1;i<=n;i++)
            scanf("%d",cost+i);

        int s=n+2;
        LL ans=INFLL;
        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        for (int i=0;i<=n;i++)
        {
//            printf ("%d %d\n",pref[i],suff[i]);
            if (pref[i]==suff[i])
            {
//                add_edge(s,i-1,0);
                ans=min(ans,dp[i]);

                break;
            }

//            printf("i=%d  pref[i]%d\n",i,pref[i]);

//            itn _v=MAP[pref[i]];
            int _v=__hash[i];
//            add_edge(i,0,cost[i]+cost[n+1-_v]);
//            printf("i=%d  pref[i]%d   sufid(_v)=%d\n",i,pref[i],_v);
            if (~_v)
            {
                for (int j=i-1;j>=0;j--)
                {
                    int _u=__hash[j];
//                    printf ("j=%d _u=%d\n",j,_u);
                    if (~_u)
                    {
						dp[i]=min(dp[i],dp[j]+cost[i-j]+cost[_u-_v]);
//                        add_edge(i,j,cost[i-j]+cost[_u-_v]);
//                        add_edge(_v,i,cost[_v-1-i]);
//                        add_edge(s,_v,0);
                        ans=min(ans,dp[i]+cost[_v-1-i]);
//                        printf ("%d --> %d %d\n",i,j,cost[i-j]+cost[_u-_v]);
                    }
                }

            }

            if (i+1==_v)
            {
				ans=min(ans,dp[i]);
//                add_edge(s,i,0);
                break;
            }

        }

		printf( "%I64d\n",min(ans,(long long)cost[n]));
//        if (~s)
//        {
//            SPFA(s);
//            printf( "%I64d\n",min(d[0],(long long )cost[n]));
//        }
//        else
//            printf("%d\n",cost[n]);

    }

}
