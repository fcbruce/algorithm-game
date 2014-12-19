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

map<string,int> MAP;
int n;
char s[111];
char country[111];
string temp;
map<string,int>::iterator it;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d",&n);
	getchar();

	for (int i=0;i<n;i++)
    {
        fgets(s,111,stdin);
        sscanf(s,"%s",country);
        temp=country;
        MAP[temp]++;
    }

    for (it=MAP.begin();it!=MAP.end();it++)
        printf("%s %d\n",it->first.c_str(),it->second);


	return 0;
}
