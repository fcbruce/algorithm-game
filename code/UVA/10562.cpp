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

char MAP[222][222];
int n;

void dfs(int x,int y)
{
    for (int i=y;MAP[x][i]=='-';i++)
    {
        if (MAP[x+1][i]!=' ' && MAP[x+1][i]!='\n' && MAP[x+1][i]!='\0')
        {
            printf("%c(",MAP[x+1][i]);
            if (x+1<n && MAP[x+2][i]=='|')
            {
                int k=i;
                while (k && MAP[x+3][k-1]=='-') k--;
                dfs(x+3,k);
            }
            printf(")");
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);getchar();

    while (tt--)
    {
        memset(MAP,0,sizeof(MAP));
        n=1;
        while (fgets(MAP[n],222,stdin),MAP[n][0]!='#') n++;

        for (int i=0;MAP[1][i]!='\n';i++)
            MAP[0][i]='-';

        if (n==1)
        {
            printf("()\n");
            continue;
        }
        printf("(");
        dfs(0,0);
        printf(")\n");
    }


    return 0;
}
