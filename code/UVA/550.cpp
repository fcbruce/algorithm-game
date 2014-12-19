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
	#endif

	int k,n,m,s,p;
	int ans;

	while (~scanf("%d%d%d",&k,&n,&m))
    {
        ans=1;
        s=n*m;
        while (s!=n)
        {
            s=s/k+(s%k)*m;
            ans++;
        }

        printf("%d\n",ans);
    }


	return 0;
}
