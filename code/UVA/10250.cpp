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

    double x1,y1,x2,y2;
    double xo,yo,x,y,x_,y_;

    while (~scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2))
    {
        xo=(x1+x2)/2;
        yo=(y1+y2)/2;
        x_=(x1-x2)/2;
        y_=(y1-y2)/2;
        x=cos(PI/2)*x_-sin(PI/2)*y_;
        y=sin(PI/2)*x_+cos(PI/2)*y_;

        printf("%.10f %.10f %.10f %.10f\n",xo+x,yo+y,xo-x,yo-y);

    }


    return 0;
}
