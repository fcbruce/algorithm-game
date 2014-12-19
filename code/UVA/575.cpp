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

int bit[32];

void init()
{
    bit[1]=1;
    for (int i=2;i<32;i++)
        bit[i]=(bit[i-1]<<1)|1;
}

char s[33];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	init();

	while (scanf("%s",s+1),strcmp(s+1,"0"))
    {
        int l=strlen(s+1);
        reverse(s+1,s+l+1);

        int ans=0;

        for (int i=1;i<=l;i++)
        {
            ans+=(s[i]-'0')*bit[i];
        }

        printf("%d\n",ans);


    }




	return 0;
}
