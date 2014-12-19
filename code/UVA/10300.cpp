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

	int tt,n,x,y,z;
	scanf("%d",&tt);

	while  (tt--)
    {
        scanf("%d",&n);
        int total=0;

        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            total+=(x*z);
        }
        printf("%d\n",total);
    }


	return 0;
}
