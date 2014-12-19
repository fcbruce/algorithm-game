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

double num[200];//数值
int op[200];//运算符

int fn,rn,fo,ro;//fn,rn num的底和顶,fo ro op的底和顶
double ans;

char s[200];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	bool flag=false;
	fn=fo=0;
	rn=-1;
	ro=0;
	op[0]=1;
	while (~scanf("%s",s))
    {
        if (flag && isdigit(s[0]))
        {
            ans=0;
            while (fn<=rn)
            {
                if (op[fn]==1)
                    ans+=num[fn];
                else
                    ans-=num[fn];

                fn++;
            }
            printf("%.2f\n",ans);
            fn=fo=0;
            rn=-1;
            ro=0;
            flag=false;
        }
/*
        if (s[0]=='0' && s[1]=='\0')
            break;
*/
        if (isdigit(s[0]))
        {
            flag=true;

            if (op[ro]==3)
            {
                num[rn]*=atoi(s);
                ro--;
                continue;
            }

            if (op[ro]==4)
            {
                num[rn]/=atoi(s);
                ro--;
                continue;
            }

            num[++rn]=atoi(s);
            continue;
        }

        flag=false;

        switch (s[0])
        {
        case '+':op[++ro]=1;break;
        case '-':op[++ro]=2;break;
        case '*':op[++ro]=3;break;
        case '/':op[++ro]=4;break;
        }
    }


	return 0;
}
