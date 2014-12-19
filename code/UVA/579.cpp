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

    int h,m;
    double dh,dm,d;
    while (scanf("%d:%d",&h,&m),h||m)
    {
        dh=(h%12)*30+m*0.5;
        dm=m*6;
        d=fabs(dh-dm);
        printf("%.3f\n",min(d,360-d));

    }

    return 0;
}
