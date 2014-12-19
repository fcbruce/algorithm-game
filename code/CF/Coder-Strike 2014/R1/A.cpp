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

char s[111];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n,k;

	scanf("%d%d",&n,&k);
	scanf("%s",s);

	if (k<=(n>>1))
	{
	    for (;k>1;k--)
            puts("LEFT");
        for (int i=0;i<n;i++)
        {
            if (i) puts("RIGHT");
            printf("PRINT %c\n",s[i]);
        }
	}
	else
    {
        for (;k<n;k++)
            puts("RIGHT");
        for (int i=n-1;i>=0;i--)
        {
            if (i!=(n-1)) puts("LEFT");
            printf("PRINT %c\n",s[i]);
        }
    }


	return 0;
}
