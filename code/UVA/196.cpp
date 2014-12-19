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
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

typedef pair<int,int> PAIR;

int n,m;
int MAP[1010][1010];
char s[100];
vector<PAIR> v[1010][1010];

void save(int i,int j)
{
    int p=0;
    int x=0,y=0;
    v[i][j].clear();
    while (s[p]!='\0')
    {
        p++;
        while (isalpha(s[p]))
        {
            x=x*26+s[p]-64;
            p++;
        }
        while (isdigit(s[p]))
        {
            y=y*10+s[p]-48;
            p++;
        }
        //printf("x=%d y=%d\n",x,y);
        v[i][j].push_back(PAIR(y,x));
        x=y=0;
    }
}

int dfs(int x,int y)
{
    if (MAP[x][y]!=-1)  return MAP[x][y];

    int res=0;

    for (int i=0;i!=v[x][y].size();i++)
        res+=dfs(v[x][y][i].first,v[x][y][i].second);

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    //    freopen("/home/fcbruce/文档/code/t1","w",stdout);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);

    while (tt--)
    {
        scanf("%d%d",&m,&n);
        memset(MAP,-1,sizeof(MAP));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%s",s);
                if (isdigit(s[0]))
                {
                    MAP[i][j]=atoi(s);
                }
                else
                {
                    //puts(s);
                    save(i,j);
                    //puts("----------------------");
                }
            }
        }

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (MAP[i][j]==-1)
                {
                    MAP[i][j]=dfs(i,j);
                }

                printf(j==m?"%d\n":"%d ",MAP[i][j]);
            }
        }
    }

    return 0;
}
