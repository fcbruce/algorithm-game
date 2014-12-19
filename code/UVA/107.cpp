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
#define eps 1e-6
#define mm

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int h,w,n;
	while (scanf("%d%d",&h,&w),h&&w)
    {
        if (w==1)
        {
            printf("%d %d\n",(int)(log(h)/log(2)),h*2-1);
            continue;
        }

        for (int i=1;i<=w;i++)
        {
            if (fabs(log(i+1)*log(w)-log(i)*log(h))<eps)
            {
                n=i;
                break;
            }
        }
        int k=1;
        int s=0,t=0;
        while (w>=1)
        {
            t+=(k*w);
            w/=n;
            s+=w;
            k*=(n+1);
        }

        printf("%d %d\n",s,t);
    }

	return 0;
}
