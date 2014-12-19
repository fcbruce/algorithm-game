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
#define mm 1000001

using namespace std;

bool isprime[mm];
int prime[mm];
int cnt;

void init ()
{
    cnt=0;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for (int i=2;i<mm;i++)
    {
        if (isprime[i])
        {
            prime[cnt++]=i;
            for (int j=i<<1;j<mm;j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    LL n;
    int tt=0;

    init();

    while (scanf("%lld",&n),~n)
    {
        for (int i=0;i<cnt;i++)
        {
            while (n%prime[i]==0)
            {
                printf("    %d\n",prime[i]);
                n/=prime[i];
            }
        }

        if (n!=1)
            printf("    %lld\n",n);

        puts("");
    }

    return 0;
}
