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

int bit[11]={0,128,64,32,16,8,0,4,2,1,0};

char code[20];
int c;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	fgets(code,20,stdin);

	while (fgets(code,20,stdin) && code[0]!='_')
    {
        c=0;
        for (int i=1;i<6;i++)
        {
            if (code[i]=='o')
                c|=bit[i];
        }

        for (int i=7;i<=10;i++)
        {
            if (code[i]=='o')
                c|=bit[i];
        }

        printf("%c",c);
    }






	return 0;
}
