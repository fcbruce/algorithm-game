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

char s[111];
int l;

bool nolow()
{
    for (int i=0;i<l;i++)
    {
        if (islower(s[i]))
            return false;
    }

    return true;
}

bool noup()
{
    for (int i=0;i<l;i++)
    {
        if (isupper(s[i]))
            return false;
    }

    return true;
}

bool nodig()
{
    for (int i=0;i<l;i++)
    {
        if (isdigit(s[i]))
            return false;
    }

    return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif

	scanf("%s",s);
	l=strlen(s);

    if (l<5)
    {
        puts("Too weak");
        return 0;
    }

    if (nolow())
    {
        puts("Too weak");
        return 0;
    }

    if (noup())
    {
        puts("Too weak");
        return 0;
    }

    if (nodig())
    {
        puts("Too weak");
        return 0;
    }

    puts("Correct");


	return 0;
}
