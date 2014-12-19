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
#define maxm
#define maxn

using namespace std;

int X[10];
int n,m;
int q[5555];
int st[5555];
bool __hash[5555];

struct __node
{
    int x,mod,fir;
}node[5555];

void write(int x)
{
    int top=-1;

    for (;~x;x=node[x].fir)
        st[++top]=node[x].x;

    while (top>=0)
        printf("%d",st[top--]);

    puts("");
}

void bfs()
{
    int f=0,r=-1,cnt=0;
    if (!n)
    {
        printf("%d\n",0);
        return ;
    }
    memset(__hash,0,sizeof __hash);
    for (int i=0;i<m;i++)
    {
        if (!X[i]) continue;
        int mod=X[i]%n;
        if (!mod)
        {
            printf("%d\n",X[i]);
            return ;
        }
        if (__hash[mod])    continue;
        __hash[mod]=true;
        node[cnt]=(__node){X[i],mod,-1};
        q[++r]=cnt;
        cnt++;
    }

    while (f<=r)
    {
        int x=q[f++];
        for (int i=0;i<m;i++)
        {
            int mod=(node[x].mod*10+X[i])%n;
            if (__hash[mod])    continue;
            __hash[mod]=true;
            node[cnt]=(__node){X[i],mod,x};
            q[++r]=cnt;
            if (!mod)
            {
                write(cnt);
                return ;
            }
            cnt++;
        }
    }

    printf("0\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d",&n))
    {
        scanf("%d",&m);

        for (int i=0;i<m;i++)
            scanf("%d",X+i);

        sort(X,X+m);

        bfs();
    }


    return 0;
}
