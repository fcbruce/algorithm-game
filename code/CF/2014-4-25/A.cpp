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

char s[222];
int n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d",&n);
	scanf("%s",s);
	int x=0;
	int l=strlen(s);
	int k=n>>1;
	for (int i=0;i<n;i++)
    {
        if (s[i]=='x')
            x++;
    }
    //ans=abs(x-k);
    int c=0;
    if (x>k)
    {
        for (int i=0;i<n && (x-c)>k;i++)
        {
            if (s[i]=='x')
            {
                s[i]='X';
                c++;
            }
        }
    }
    else
    {
        for (int i=0;i<n && x+c<k;i++)
        {
            if (s[i]=='X')
            {
                s[i]='x';
                c++;
            }
        }
    }

    printf("%d\n",c);
    puts(s);


	return 0;
}
