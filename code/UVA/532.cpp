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

int vis[33][33][33];
int fx,fy,fz,tx,ty,tz;
int L,R,C;
int f,r;

int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};

struct record
{
    int x,y,z,t;
    record(int xx=0,int yy=0,int zz=0,int tt=0)
    {
        x=xx;y=yy;z=zz;t=tt;
    }
    record(const record &r)
    {
        x=r.x;y=r.y;z=r.z;t=r.t;
    }
}q[33333];

int BFS()
{
    while (f<=r)
    {
        record n(q[f++]);

        //printf("%d %d %d %d\n",n.x,n.y,n.z,n.t);

        if (n.x==tx && n.y==ty && n.z==tz)   return n.t;


        int x,y,z;

        for (int i=0;i<6;i++)
        {
            x=n.x+dx[i];
            y=n.y+dy[i];
            z=n.z+dz[i];

            if (vis[x][y][z]!=-1)
            {
                vis[x][y][z]=-1;
                q[++r]=record(x,y,z,n.t+1);
            }
        }
    }

    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d%d",&L,&R,&C),L||R||C)
    {
        char c;
        memset(vis,-1,sizeof(vis));
        for (int i=1;i<=L;i++)
        {
            getchar();
            for (int j=1;j<=R;j++)
            {
                for (int k=1;k<=C;k++)
                {
                    c=getchar();
                    if (c=='#') continue;
                    vis[i][j][k]=0;
                    if (c=='S')
                    {
                        fx=i;fy=j;fz=k;
                    }
                    if (c=='E')
                    {
                        tx=i;ty=j;tz=k;
                    }
                }
                getchar();
            }
        }

        //printf("%d %d %d %d\n",fx,fy,fz,0);

        q[f=r=0]=record(fx,fy,fz,0);
        vis[fx][fy][fz]=-1;
        int k=BFS();
        if (~k)
        {
            printf("Escaped in %d minute(s).\n",k);
        }
        else
        {
            printf("Trapped!\n");
        }


    }


    return 0;
}
