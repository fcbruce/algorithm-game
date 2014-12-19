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
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

using namespace std;

long long a[801];

bool isprime[888];
int prime[888];
int cnt;
long long fac[888],cfac[888];
int cntf;

void init ()
{
    cnt=0;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for (int i=2;i<801;i++)
    {
        if (isprime[i])
        {
            prime[cnt++]=i;
            for (int j=i<<1;j<801;j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    int x,y;

    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    init();

    while (~scanf("%d%d",&x,&y))
    {
        memset(a,0,sizeof(a));
        int p=1;
        double l=1;

        int k=y;
        cntf=0;
        memset(cfac,0,sizeof(cfac));
        for (int i=0;i<cnt;i++)
        {
            if (k%prime[i]==0)
                fac[cntf++]=prime[i];
            while (k%prime[i]==0)
            {
                cfac[cntf-1]++;
                k/=prime[i];
            }

            if (k==1)   break;
        }

        for (int i=2;i<=x;i++)
        {
            l+=log((double)i)/log((double)y);
            int k=i;
            int t=0;
            for (int j=0;j<cntf;j++)
            {
                //printf("%d\n",k);
                while (k%fac[j]==0)
                {
                    a[fac[j]]++;
                    k/=fac[j];
                }

                if (k==1)   break;
            }

        }

       // printf("%d\n",cntf);

        long long ans=INF;

        for (int i=0;i<cntf;i++)
        {
            ans=min(ans,a[fac[i]]/cfac[i]);
        }

        printf("%lld %d\n",ans,(int)(l+eps));
    }


    return 0;
}
