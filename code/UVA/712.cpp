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
#include<list>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

char str[10];
char x[1000];
char leave[22222];
int px[1000];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m;
    int tt=1;

    while (scanf("%d",&n),n)
    {
        printf("S-Tree #%d:\n",tt++);
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            sscanf(str+1,"%d",px+i);
            px[i]--;
        }

        scanf("%s",leave);

        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%s",x);
            int pos=1;
            for (int j=0;j<n;j++)
            {
                if (x[px[j]]=='0')
                {
                    pos<<=1;
                }
                else
                {
                    pos<<=1;
                    pos+=1;
                }
            }
            pos-=strlen(leave);
            printf("%c",leave[pos]);
        }

        puts("\n");


    }

    return 0;
}
