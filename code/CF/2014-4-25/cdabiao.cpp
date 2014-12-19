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
		freopen("t","r",stdin);
		freopen("t1","w",stdout);
	#endif
	int k;
	for (int n=1;n<=1000000;n++)
    {
        k=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                k^=(i%j);
        printf("%d,",k);
    }

	return 0;
}
