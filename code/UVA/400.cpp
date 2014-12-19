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

string filename[111];
int MAXSIZE,numline,row,n;
char f[111];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (scanf("%d",&n)==1)
    {
        MAXSIZE=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",f);
            filename[i]=f;
            MAXSIZE=max(MAXSIZE,(int)filename[i].size());
        }
        MAXSIZE=min(60,MAXSIZE+2);
        numline=60/MAXSIZE;
        row=n/numline;
        if (n%numline)  row++;
        sort(filename,filename+n);
        puts("------------------------------------------------------------");
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<numline;j++)
            {
                if (i+j*row>=n) break;
                printf("%s",filename[i+j*row].c_str());
                for (int k=filename[i+j*row].size();k<MAXSIZE;k++)
                    printf(" ");
            }
            puts("");
        }


    }


	return 0;
}
