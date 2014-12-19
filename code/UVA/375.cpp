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
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    double b,h,a1,a2;
    int tt;

    scanf("%d",&tt);

    while (tt--)
    {
        scanf("%lf%lf",&b,&h);
        b/=2;
        a1=atan(h/b)/2;
        a2=tan(a1);
        a1=tan(2*a1);

        double sum=0;
        while (true)
        {
            double r=b*a2;
            if (r<1e-6) break;
            sum+=r;
            h-=2*r;
            b=h/a1;
        }
        printf("%13.6f\n",sum*2*PI);
        if (tt)  puts("");
    }

    return 0;
}
