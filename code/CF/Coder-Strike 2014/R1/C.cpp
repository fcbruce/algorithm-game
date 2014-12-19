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
#define mm 100005

using namespace std;

char s1[mm],s2[mm],ans[mm];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n;
	int l;

	scanf("%d",&n);

	for (int i=0;i<n;i++)
    {
        scanf("%s",s1);
        l=strlen(s1);
        for (int j=0;j<l;j++)
        {
            if (s1[j]!='?' && ans[j]!='?')
            {
                if (ans[j]=='\0')
                {
                    ans[j]=s1[j];
                }
                else
                {
                    if (ans[j]!=s1[j])
                    {
                        ans[j]='?';
                    }
                }
            }
        }



    }
	for (int i=0;i<l;i++)
        {
            if (ans[i]=='\0')
                ans[i]='x';
        }

        puts(ans);

	return 0;
}
