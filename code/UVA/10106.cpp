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

char s1[555],s2[555];
int n1[555],n2[555],ans[555],l1,l2,h;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (~scanf("%s%s",s1,s2))
    {
        memset(ans,0,sizeof(ans));
        l1=strlen(s1);
        l2=strlen(s2);

        for (int i=0;i<l1;i++)
            n1[i]=s1[l1-i-1]-'0';
        for (int i=0;i<l2;i++)
            n2[i]=s2[l2-i-1]-'0';

        for (int i=0;i<l1;i++)
        {
            for (int j=0;j<l2;j++)
            {
                ans[i+j]+=(n1[i]*n2[j]);
                ans[i+j+1]+=(ans[i+j]/10);
                ans[i+j]%=10;
            }
        }

        for (int i=505;i>=0 && ans[i]==0;i--)
            h=i;

        if (h==0)
            puts("0");
        else
        {
            for (int i=h-1;i>=0;i--)
                printf("%d",ans[i]);
            puts("");
        }
    }


	return 0;
}
