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

char s[100][100];
bool f;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int cnt=0;
	int tt=1;
	f=true;

	while(~scanf("%s",s[cnt]))
    {
        if (strcmp(s[cnt],"9")==0)
        {
            printf("Set %d is ",tt++);
            if (f)
            {
                puts("immediately decodable");
            }
            else
            {
                puts("not immediately decodable");
            }

            f=true;
            cnt=0;

            continue ;
        }
        for (int i=0;i<cnt && f;i++)
        {
            bool ff=false;

            for (int j=0;j<min(strlen(s[i]),strlen(s[cnt])) && !ff;j++)
            {
                if (s[i][j]!=s[cnt][j])
                    ff=true;
            }

            f=ff;
        }

        cnt++;
    }




	return 0;
}
