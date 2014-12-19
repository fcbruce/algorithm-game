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

	char c;

	int cnt;

	cnt=0;

	while ((c=getchar())!=EOF)
    {

        if (isdigit(c))
        {
            cnt+=(c-'0');
            continue;
        }

        if (c=='\n' || c=='!')
        {
            puts("");
            continue;
        }

        if (c=='b')
            c=' ';

        for (int i=0;i<cnt;i++)
            putchar(c);

        cnt=0;



    }


	return 0;
}
