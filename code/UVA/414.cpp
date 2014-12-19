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

char s[30];
int n,total,MIN,now;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while(scanf("%d",&n)&&n)
    {
        getchar();
        total=0;
        MIN=INF;
        for (int i=0;i<n;i++)
        {
            fgets(s,30,stdin);
            now=0;
            for (int j=0;j<25;j++)
            {
                if (s[j]==' ')
                    now++;
            }
            MIN=min(MIN,now);
            total+=now;
        }

        printf("%d\n",total-MIN*n);
    }


	return 0;
}
