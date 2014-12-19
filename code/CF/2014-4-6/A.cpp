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

int l[111];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n,m,x;

	memset(l,0,sizeof(l));

	scanf("%d%d",&n,&m);

	for (int i=0;i<m;i++)
    {
        scanf("%d",&x);

        for (int j=x;j<=n;j++)
        {
            if (l[j]==0)
            {
                l[j]=x;
            }
        }
    }

    for (int i=1;i<=n;i++)
    {
        printf("%d ",l[i]);
    }

    puts("");


	return 0;
}
