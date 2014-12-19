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

int dp[100001];
int pre[100001];
int num[100001],b[100001],c[100001];
int a[40];
itn s,l;

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d",&s,&l);

    for (int i=1;i<=l;i++)
    {
        int k=1,t=i;
        while (!(t&1))
        {
            k++;
            t>>=1;
        }
        a[k]++;

    }

//    for (int i=0;i<15;i++)
//    {
//        printf("%d:%d ",i,a[i]);
//    }
//    puts("");
//


    memset(pre,-1,sizeof pre);
    memset(dp,0,sizeof dp);
    dp[0]=1;

    for (int i=1;i<20;i++)
    {
        itn k=1<<(i-1);
        itn kk=1;


      //  printf("\nk=%d\n a[i]=%d\n",k,a[i]);

        while (kk<=a[i])
        {
            //printf("kk=%d ",kk);
            for (itn j=s;j>=k*kk;j--)
            {
                if (dp[j-kk*k]&& dp[j]==0)
                {
                    dp[j]=1;
                    pre[j]=j-kk*k;
                    num[j]=kk;
                    b[j]=k;
                }

            }
            a[i]-=kk;
            kk<<=1;
        }

        if (a[i])
        {
//            printf("kk=%d ",a[i]);
            for (itn j=s;j>=k*a[i];j--)
            {
                if (dp[j-a[i]*k] && dp[j]==0)
                {
                    dp[j]=1;
                    pre[j]=j-a[i]*k;
                    num[j]=a[i];
                    b[j]=k;
                }

            }
        }
    }

//    for (int i=0;i<=s;i++)
//    {
//        printf("%d ",dp[i]);
//    }
//puts("");
    if (dp[s])
    {
        int k=s;
        while (pre[k]!=-1)
        {
            c[b[k]]+=num[k];
//            printf("%d %d\n",num[k],b[k]);
            k=pre[k];
        }
//        puts("");
        vector <int> v;
        for (int i=1;(1<<(i-1))<100001;i++)
        {
            int tt=1<<(i-1);
//            if (c[t])
//            {
//                printf("%d %d\n",t,c[t]);
//            }
            int x=0;
            for (int j=0;j<c[tt];j++)
            {
                v.push_back((x<<i)|tt);
                x++;
            }
        }
        printf("%d\n",v.size());
        for (int i=0;i<v.size();i++)
        {
            printf("%d ",v[i]);
        }
    }
    else
    {
        puts("-1");
    }

    return 0;
}
