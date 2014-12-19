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

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;

    scanf("%d",&tt);

    int n;
    for (int t=1;t<=tt;t++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d",t,n);
        int cnt=0;
        for (int i=2;i<n;i++)
        {
            if (n%i==0)
            {
                printf(" = %d * %d",i,n/i);
                cnt++;
            }
            if (cnt==2) break;
        }
        puts("");

    }

    return 0;
}
