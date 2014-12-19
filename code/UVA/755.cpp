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

char alp[30]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char num[30]="22233344455566677778889999";
map<string,int>MAP;
map<string,int>::iterator it;
int n;
char s[111];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt,cc=0;
	scanf("%d",&tt);

	while (tt--)
    {
        MAP.clear();
        if (cc) puts("");
        cc++;

        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",s);
            int l=strlen(s);
            string tel;
            for (int j=0;j<l;j++)
            {
                if (isalpha(s[j]))
                    tel+=num[s[j]-'A'];
                if (isdigit(s[j]))
                    tel+=s[j];
                if (tel.size()==3)
                    tel+='-';
            }
            MAP[tel]++;
        }

        bool f=true;

        for (it=MAP.begin();it!=MAP.end();it++)
        {
            if (it->second>1)
            {
                printf("%s %d\n",(it->first).c_str(),it->second);
                f=false;
            }
        }

        if (f)
            puts("No duplicates.");
    }


	return 0;
}
