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
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    double a,b,n,m,s;

    while (scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n),a||b||s||m||n)
    {
        double angle=atan((n*b)/(m*a))*180/PI;
        double v=sqrt(sqr(n*b)+sqr(m*a))/s;
        printf("%.2f %.2f\n",angle,v);
    }


    return 0;
}
