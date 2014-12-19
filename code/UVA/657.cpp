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

char MAP[55][55];
int dir[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,p;
vector<int> v;

void dfs2(int x,int y)
{
    MAP[x][y]='*';
    for (int i=0;i<4;i++)
    {
        int X=x+dir[i][0],Y=y+dir[i][1];
        if (MAP[X][Y]=='X')
        {
            dfs2(X,Y);
        }
    }
}

void dfs1(int x,int y)
{
    if (MAP[x][y]=='X')
    {
        p++;
        dfs2(x,y);
    }
    MAP[x][y]='.';
    for (int i=0;i<4;i++)
    {
        int X=x+dir[i][0],Y=y+dir[i][1];
        if (MAP[X][Y]=='*' || MAP[X][Y]=='X')
        {
            dfs1(X,Y);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt=0;

    while (scanf("%d%d",&m,&n),n||m)
    {
        memset(MAP,'.',sizeof(MAP));
        v.clear();

        for (int i=1;i<=n;i++)  scanf("%s",&MAP[i][1]);

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (MAP[i][j]=='*' || MAP[i][j]=='X')
                {
                    p=0;
                    dfs1(i,j);
                    v.push_back(p);
                }
            }
        }

        sort(v.begin(),v.end());

        printf("Throw %d\n",++tt);

        if (v.size())   printf("%d",v[0]);

        for (int i=1;i<v.size();i++)
        {
            printf(" %d",v[i]);
        }

        printf("\n\n");
    }


    return 0;
}
