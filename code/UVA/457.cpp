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

int dna[11];
int dish[2][44];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt,f;
	scanf("%d",&tt);

	for (int t=0;t<tt;t++)
    {
        if (t)  puts("");
        f=0;
        for (int i=0;i<10;i++)
            scanf("%d",dna+i);

        memset(dish,0,sizeof(dish));
        dish[0][20]=1;

        for (int i=0;i<50;i++)
        {
            for (int j=1;j<=40;j++)
            {
                switch(dish[f][j])
                {
                    case 0:putchar(' ');break;
                    case 1:putchar('.');break;
                    case 2:putchar('x');break;
                    case 3:putchar('W');break;
                }

                dish[f^1][j]=dna[dish[f][j-1]+dish[f][j]+dish[f][j+1]];
            }

            //for (int j=1;j<=40;j++) dish[j]=dna[dish[j-1]+dish[j]+dish[j+1]];
            f^=1;
            puts("");
        }
    }


	return 0;
}
