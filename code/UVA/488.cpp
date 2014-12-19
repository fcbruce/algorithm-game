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
#define sqr(x) (x)*(x)
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

	int tt,n,m;
	bool f=false;

	scanf("%d",&tt);

	while (tt--)
    {
        if (f)
            puts("");

        f=true;
        scanf("%d%d",&n,&m);
        for (int i=0;i<m;i++)
        {
            if (i) puts("");
            for (int j=1;j<=n;j++)
            {
                for (int k=0;k<j;k++)
                    printf("%d",j);
                puts("");
            }
            for (int j=n-1;j;j--)
            {
                for (int k=0;k<j;k++)
                    printf("%d",j);
                puts("");
            }
        }
    }


	return 0;
}
