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

int vis[10][10];
char fs[5],ts[5];
int fx,fy,tx,ty,t;
int dx[]={-1,1,2,2,1,-1,-2,-2};
int dy[]={2,2,1,-1,-2,-2,-1,1};

struct record
{
    int x,y,step;
}q[100];;
int f,r;

inline void init()
{
    memset(vis,0,sizeof(vis));
}

int bfs()
{
    while (f<=r)
    {
        int nx=q[f].x;
        int ny=q[f].y;
        int step=q[f].step;
        f++;

        if (nx==tx && ny==ty)
            return step;

        for (int i=0;i<8;i++)
        {
            int x=nx+dx[i];int y=ny+dy[i];
            if (x>0 && x<9 && y>0 && y<9 && vis[x][y]==0)
            {
                ++r;
                q[r].x=x;q[r].y=y;q[r].step=step+1;
                vis[x][y]=1;
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%s %s",fs,ts)!=EOF)
    {
        fx=fs[0]-'a'+1;
        fy=fs[1]-'0';
        tx=ts[0]-'a'+1;
        ty=ts[1]-'0';

        q[f=r=0].x=fx;q[0].y=fy,q[0].step=0;
        vis[fx][fy]=1;
        init();
        t=0;
        printf("To get from %s to %s takes %d knight moves.\n",fs,ts,bfs());
    }



    return 0;
}
