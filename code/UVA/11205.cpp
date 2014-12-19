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

//set<string> s;
//map<string,int> MAP;
set<int> s;
//char str[120][20];
int p,n;
int a[120][20];
int vis[65535];
itn h[20];
int MIN;

void dfs(int x,int y)
{
    if (x>p)   return ;

    //memset(vis,0,sizeof vis);
    set<int> s;
    bool flag=true;

    //printf("%d %d\n",x,y);

    for (int i=0;i<n;i++)
    {
        int code=0;
        for (int j=0;j<p;j++)
        {
            code<<=1;
            if (h[j]) code+=a[i][j];
        }
        //printf("code=%d\n",code);
        if (s.count(code))
        {
            flag=false;
            break;
        }
        s.insert(code);
    }

    if (flag)
    {
        MIN=min(MIN,y);
        //printf("y=%d\n",y);
    }

    h[x]=1;
    dfs(x+1,y+1);
    h[x]=0;
    dfs(x+1,y);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d%d",&p,&n);
        for (int i=0;i<n;i++)
        {
            for (itn j=0;j<p;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        MIN=INF;

        memset(h,0,sizeof h);
        dfs(0,0);

        printf("%d\n",MIN);

    }


    return 0;
}
