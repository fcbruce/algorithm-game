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

int HASH[12345];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int z,i,m,l;
	int tt=0,cnt;

	while (scanf("%d%d%d%d",&z,&i,&m,&l),z||i||m||l)
    {
        tt++;
        printf("Case %d: ",tt);

        memset(HASH,0,sizeof(HASH));
        cnt=0;
        while (true)
        {
            l=(z*l+i)%m;
            if (HASH[l])    break;
            cnt++;
            HASH[l]=1;
        }

        printf("%d\n",cnt);

    }



	return 0;
}
