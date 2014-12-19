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

int n,a[55],cnt;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt;
	scanf("%d",&tt);

	while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        cnt=0;
        for (int i=0;i<n;i++)
        {
            for (int j=1;j<n-i;j++)
            {
                if (a[j-1]>a[j])
                {
                    cnt++;
                    swap(a[j],a[j-1]);
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",cnt);
    }


	return 0;
}
