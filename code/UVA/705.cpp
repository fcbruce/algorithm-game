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

int w,h,cnt,step,MAX;
int vis[160][160];
char MAP[160][160];
bool f;

void dfs(int x,int y)
{
    if (MAP[x][y]=='\\' || MAP[x][y]=='/' || vis[x][y]==1)
        return ;
    if (MAP[x][y]=='\0')
    {
        f=false;
        return ;
    }

    vis[x][y]=1;
    step++;
    dfs(x+1,y);dfs(x-1,y);dfs(x,y+1);dfs(x,y-1);

    if (MAP[x+1][y]=='\\' && MAP[x][y+1]=='\\') dfs(x+1,y+1);
    if (MAP[x-1][y]=='\\' && MAP[x][y-1]=='\\') dfs(x-1,y-1);
    if (MAP[x][y+1]=='/' && MAP[x-1][y]=='/') dfs(x-1,y+1);
    if (MAP[x+1][y]=='/' && MAP[x][y-1]=='/') dfs(x+1,y-1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt=0;
    char c;

    while (scanf("%d%d",&w,&h),w||h)
    {
        getchar();
        memset(MAP,'\0',sizeof(MAP));
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=h;i++)
        {
            for (int j=1;j<=w;j++)
            {
                c=getchar();
                if (c=='\\')
                {
                    MAP[2*i-1][2*j-1]=MAP[2*i][2*j]='\\';
                    MAP[2*i-1][2*j]=MAP[2*i][2*j-1]=' ';
                }
                else
                {
                    MAP[2*i-1][2*j-1]=MAP[2*i][2*j]=' ';
                    MAP[2*i-1][2*j]=MAP[2*i][2*j-1]='/';
                }
            }
            getchar();
        }

        w<<=1;h<<=1;
        cnt=MAX=0;

        for (int i=1;i<=h;i++)
        {
            for (int j=1;j<=w;j++)
            {
                if (MAP[i][j]==' ' && vis[i][j]==0)
                {
                    f=true;
                    step=0;
                    dfs(i,j);
                    if (f)
                    {
                        cnt++;
                        MAX=max(MAX,step);
                    }
                }
            }
        }

        printf("Maze #%d:\n",++tt);
        if (cnt)
        {
            printf("%d Cycles; the longest has length %d.\n\n",cnt,MAX);
        }
        else
        {
            printf("There are no cycles.\n\n");
        }

    }



    return 0;
}
