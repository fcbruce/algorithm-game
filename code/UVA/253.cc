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

int way[24][6]={1,2,3,4,5,6,   1,3,5,2,4,6,    1,5,4,3,2,6,    1,4,2,5,3,6,
                2,4,6,1,3,5,   2,6,3,4,1,5,    2,3,1,6,4,5,    2,1,4,3,6,5,
                3,2,6,1,5,4,   3,6,5,2,1,4,    3,5,1,6,2,4,    3,1,2,5,6,4,
                6,5,3,4,2,1,   6,4,5,2,3,1,    6,2,4,3,5,1,    6,3,2,5,4,1,
                5,3,6,1,4,2,   5,1,3,4,6,2,    5,4,1,6,3,2,    5,6,4,3,1,2,
                4,5,6,1,2,3,   4,1,5,2,6,3,    4,2,1,6,5,3,    4,6,2,5,1,3};

char s1[20];
char s2[20];
bool f;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (~scanf("%s",s1))
    {
        strcpy(s2,&s1[6]);
        s1[6]='\0';
        for (int i=0;i<24;i++)
        {
            f=true;
            for (int j=0;j<6;j++)
            {
                if (s1[j]!=s2[way[i][j]-1])
                {
                    f=false;
                    break;
                }
            }


            if (f)
                break;
        }

        if (f)
            puts("TRUE");
        else
            puts("FALSE");
    }



	return 0;
}
