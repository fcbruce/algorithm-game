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

char MAP[30][30];
int vis[30][30][4][5];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int fx,fy,tx,ty,n,m;

struct record
{
    int x,y;
    int dir;
    int t;
    int col;

    record(){};
    record(int xx,int yy,int tt,int dd,int cc)
    {
        x=xx;y=yy;t=tt;dir=dd;col=cc;
    }
    record(const record &r)
    {
        x=r.x;y=r.y;t=r.t;
        dir=r.dir;col=r.col;
    }
    friend bool operator < (const record &x,const record &y)
    {
        return y.t<x.t;
    }
};

void bfs()
{
    int x,y;
    memset(vis,0x3f,sizeof vis);
    priority_queue<record> q;

    q.push(record(fx,fy,0,0,0));
    vis[fx][fy][0][0]=0;

    while (!q.empty())
    {
        record r=q.top();q.pop();

        if (r.x==tx && r.y==ty && (r.col%5)==0)
        {
            printf("minimum time = %d sec\n",r.t);
            return ;
        }

        for (int i=0;i<4;i++)
        {
            x=r.x+dx[i];y=r.y+dy[i];

            if (MAP[x][y]=='.')
            {

                if (i==r.dir)
                {
                    if (vis[x][y][i][(r.col+1)%5]>r.t+1)
                    {
                        q.push(record(x,y,r.t+1,i,(r.col+1)%5));
                        vis[x][y][i][(r.col+1)%5]=r.t+1;
                    }
                    continue;
                }
                if (abs(i-r.dir)==2)
                {
                    if (vis[x][y][i][(r.col+1)%5]>r.t+3)
                    {
                        q.push(record(x,y,r.t+3,i,(r.col+1)%5));
                        vis[x][y][i][(r.col+1)%5]=r.t+3;
                    }
                    continue;
                }
                if (vis[x][y][i][(r.col+1)%5]>r.t+2)
                {
                    q.push(record(x,y,r.t+2,i,(r.col+1)%5));
                    vis[x][y][i][(r.col+1)%5]=r.t+2;
                }

            }

        }
    }

    puts("destination not reachable");
    return ;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt=0;

    while (scanf("%d%d",&n,&m),n||m)
    {
        char c;
        getchar();

        if (tt) puts("");
        printf("Case #%d\n",++tt);

        memset(MAP,'#',sizeof(MAP));

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                c=getchar();
                if (c!='#')
                    MAP[i][j]='.';

                if (c=='S')
                {
                    fx=i;fy=j;
                }
                if (c=='T')
                {
                    tx=i;ty=j;
                }
            }
            getchar();
        }

        bfs();

    }

    return 0;
}
