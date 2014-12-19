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

int ans[111];
int plu[111];
char str[111];
int h;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	memset(ans,0,sizeof(ans));

	while (scanf("%s",str),str[0]!='0')
    {
        int l=strlen(str);

        for (int i=0;i<l;i++)
        {
            ans[i]+=(str[l-i-1]-'0');
            if (ans[i]>9)
            {
                ans[i+1]+=(ans[i]/10);
                ans[i]%=10;
            }
            h=i;
        }
        while (ans[h+1]>9)
        {
            ans[h+2]+=(ans[h+1]/10);
            ans[h+1]%=10;
            h++;
        }


    }

    for (int i=111;i>=0;i--)
    {
        if (ans[i]==0)
            h=i;
        else
            break;
    }
    h--;
    if (h==-1)
        puts("0");
    else
    {
        for (;h>=0;h--)
        {
            printf("%d",ans[h]);
        }
        puts("");
    }


	return 0;
}
