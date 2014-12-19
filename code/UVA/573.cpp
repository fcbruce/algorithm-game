#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int h,u,d,f;
double H,U,D,F;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (scanf("%d%d%d%d",&h,&u,&d,&f),h)
    {
        int day=0;
        double x=0;
        H=h;
        U=u;
        D=d;
        F=U*f/100.0;
        while (true)
        {
            ++day;
            x+=U;
            if (x>H)
            {
                printf("success on day %d\n",day);
                break;
            }

            x-=D;
            if (x<0)
            {
                printf("failure on day %d\n",day);
                break;
            }
            U-=F;
            U=max(U,0.0);

        }
    }



	return 0;
}
