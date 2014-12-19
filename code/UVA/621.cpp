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

char s[200];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt;

	scanf("%d",&tt);getchar();
	while (tt--)
    {
        fgets(s,200,stdin);
        s[strlen(s)-1]='\0';
        if (s[strlen(s)-1]=='5')
        {
            puts("-");
            continue;
        }
        if (s[0]=='9')
        {
            puts("*");
            continue;
        }
        if (s[0]=='1' && strlen(s)>1)
        {
            puts("?");
            continue;
        }
        puts("+");
    }

	return 0;
}
