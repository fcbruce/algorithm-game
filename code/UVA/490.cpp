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

char s[111][111];
int n,m;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	n=0;
	m=0;

	memset(s,0,sizeof(s));

	while (fgets(s[n],111,stdin)!=NULL)
    {
        m=max(m,(int)strlen(s[n]));
        n++;
    }

	for (int i=0;i<m-1;i++)
    {
        for (int j=n-1;j>=0;j--)
        {
            if (s[j][i]=='\0' || s[j][i]=='\n')
                putchar(' ');
            else
                putchar(s[j][i]);
        }
        printf("\n");
    }




	return 0;
}
