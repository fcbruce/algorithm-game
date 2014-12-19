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

char s[82222];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	s[0]=' ';

	int cnt;

	while (fgets(s+1,82222,stdin))
    {
        int l=strlen(s);
        cnt=0;
        for (int i=0;i<l;i++)
        {
            if (!isalpha(s[i]))
                s[i]=' ';
            if (isalpha(s[i]) && s[i-1]==' ')
                cnt++;
        }

        printf("%d\n",cnt);
    }


	return 0;
}
