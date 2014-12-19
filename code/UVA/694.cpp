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
		freopen("t","r",stdin);
	#endif

	LL a,l,t,cnt=0;

	while (scanf("%lld%lld",&a,&l)&&(~a)&&(~l))
    {
        cnt++;
        printf("Case %lld: A = %lld, limit = %lld, number of terms = ",cnt,a,l);
        t=0;
        while ((++t)&&a!=1)
        {
            //t++;
            if ((a&1)==1)
            {
                a*=3;
                a++;
                if (a>l)
                    break;
            }
            else
            {
                a>>=1;
            }

        }
        printf("%lld\n",t);

    }


	return 0;
}
