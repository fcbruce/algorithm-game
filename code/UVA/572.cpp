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

char MAP[111][111];
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int n,m,ans;

void dfs(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        if (MAP[x+dir[i][0]][y+dir[i][1]]=='@')
        {
           // printf("\t%d %d\n",x+dir[i][0],y+dir[i][1]);
            MAP[x+dir[i][0]][y+dir[i][1]]='*';
            dfs(x+dir[i][0],y+dir[i][1]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d",&n,&m),m||n)
    {
        memset(MAP,'*',sizeof(MAP));
        getchar();
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                MAP[i][j]=getchar();
            }
            getchar();
        }

        ans=0;

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (MAP[i][j]=='@')
                {
                //    printf("%d %d\n",i,j);
                    ans++;
                    MAP[i][j]='*';
                    dfs(i,j);
                }
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
