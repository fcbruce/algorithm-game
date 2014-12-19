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

//double dp[101][101];
double dp[101];
double p[101];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lf",&p[i]);

    sort(p,p+n);
    reverse(p,p+n);
    double MAX=p[0];
    dp[0]=p[0];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==j) continue;

//            printf("%f %f\n",p[i]*(1-p[j]),p[j]*(1-p[i]));

            MAX=max(MAX,p[i]*(1-p[j])+p[j]*(1-p[i]));
        }
    }

    printf("%.9f\n",MAX);


    return 0;
}
