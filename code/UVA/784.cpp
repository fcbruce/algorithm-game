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

char MAP[40][100];
char s[100];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
pair<int,int> q[4000];
int f,r;

void bfs()
{
    while (f<=r)
    {
        pair<int,int> p=q[f++];
        for (int i=0;i<4;i++)
        {
            int X=p.first+dx[i],Y=p.second+dy[i];
            if (X>=0 && Y>=0 && MAP[X][Y]==' ')
            {
                MAP[X][Y]='#';
                q[++r]=pair<int,int>(X,Y);
            }
        }
    }

}

void output()
{
    for (int i=0;MAP[i][0];i++)
    {
        for (int j=0;MAP[i][j];j++)
        {
            putchar(MAP[i][j]);
        }
        puts("");
    }

    char c;
    while (c=getchar(),c!='\n')
        putchar(c);
    printf("_\n");
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
        char c;
        int x,y,n,m,X,Y;
        x=y=n=m=0;
        while (c=getchar(),c!='_')
        {
            if (c=='\n')
            {
                x++;
                y=0;
                continue;
            }
            if (c=='*')
            {
                X=x;Y=y;
            }
            MAP[x][y++]=c;
        }

        MAP[X][Y]='#';
        q[0]=pair<int,int>(X,Y);
        f=r=0;
        bfs();

        output();
    }

    return 0;
}
