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
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

int a[7][7],p[7];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    for (int i=1;i<=5;i++)
    {
        for (int j=1;j<=5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    long long ans=0,MAX=0;

    for (int i=1;i<=5;i++)
        p[i]=i;

        ans=0;
        int t=0;
    for (int i=0;i<6;i++)
    {
        for (int j=i+1;j<5;j+=2)
        {
            ans+=(a[p[j]][p[j+1]]+a[p[j+1]][p[j]]);
            //printf("%d %d\n",p[j],p[j+1]);
        }
    }
    //(g23 + g32 + g15 + g51) + (g13 + g31 + g54 + g45) + (g15 + g51) + (g54 + g45) 
    //ans=a[p]
    //cout<<t<<endl;
    //cout<<ans<<endl;
     MAX=max(MAX,ans);

    int c=1;

    while (next_permutation(p+1,p+6)){
        ans=0;
        for (int i=0;i<6;i++)
        {
            for (int j=i+1;j<5;j+=2)
            {
                ans+=(a[p[j]][p[j+1]]+a[p[j+1]][p[j]]);
            }
        }
        MAX=max(MAX,ans);
        c++;
        //cout<<ans<<endl;
    }

    cout<<MAX<<endl;


    return 0;
}
