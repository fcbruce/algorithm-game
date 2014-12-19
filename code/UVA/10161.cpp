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
	//	freopen("t","r",stdin);
	#endif

	int n,r,c,k;

	while (scanf("%d",&n),n)
    {
        k=sqrt(n);
        if (k&1)
        {
            if (sqr(k)==n)
            {
                r=k;
                c=1;
            }
            else
                if (sqr(k)+k>=n)
                {
                    r=k+1;
                    c=n-sqr(k);
                }
                else
                {
                    c=k+1;
                    r=sqr(k+1)-n+1;
                }
        }
        else
        {
            if (sqr(k)==n)
            {
                r=1;
                c=k;
            }
            else
                if (sqr(k)+k>=n)
                {
                    c=k+1;
                    r=n-sqr(k);
                }
                else
                {
                    r=k+1;
                    c=sqr(k+1)-n+1;
                }
        }
        printf("%d %d\n",c,r);
    }

	return 0;
}
