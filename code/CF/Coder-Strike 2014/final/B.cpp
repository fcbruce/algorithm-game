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

char s[123456];
char al[12]="AHIMOTUVWXY";
bool f;
char *p=NULL;

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif

	scanf("%s",s);
	int l=strlen(s);
	//Aprintf("%d\n",l);
    f=true;
	for (int i=0;i<=(l>>1);i++)
    {
        //puts("f");
        if (s[i]!=s[l-1-i])
        {
            f=false;
            break;
        }
        else
        {
            p=strchr(al,s[i]);
            if (p==NULL)
            {
                f=false;
                break;
            }
            p=NULL;
        }
    }

    if (f)
        puts("YES");
    else
        puts("NO");

	return 0;
}
