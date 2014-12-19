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

int g[30][30];
int in[30],out[30];
int pre[30];
int vis[30];
int n,m;

void init()
{
    for (int i=0;i<30;i++)
    {
        pre[i]=i;
    }
    memset(g,0,sizeof g);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    memset(vis,0,sizeof vis);
}

int root(int x)
{
    if (pre[x]==x)return x;

    return pre[x]=root(pre[x]);
}

void intree(int x,int y)
{
    pre[root(x)]=pre[root(y)];
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);

    while (tt--)
    {
        init();
        char s[1001];
        int u,v;
        scanf("%d",&n);

        for (int i=0;i<n;i++)
        {
            scanf("%s",s);
            u=s[0]-'a';
            v=s[strlen(s)-1]-'a';
            g[u][v]=vis[u]=vis[v]=1;
            out[u]++;
            in[v]++;
            intree(u,v);
        }

        int r=-1,f=0,t=0;
        bool flag=true;

        for (int i=0;i<30;i++)
        {
            if (vis[i])
            {
                if (r==-1)
                {
                    r=root(i);
                }
                else
                {
                    if (r!=root(i))
                    {
                        flag=false;
                        break;
                    }
                }

                if (in[i]==out[i]-1)
                {
                    f++;
                    continue;
                }
                if (in[i]==out[i]+1)
                {
                    t++;
                    continue;
                }
                if (in[i]!=out[i])
                {
                    flag=false;
                }
            }
        }

        if (flag && ((f==0 && t==0)||(f==1||t==1)))
        {
            puts("Ordering is possible.");
        }
        else
        {
            puts("The door cannot be opened.");
        }




    }

    return 0;
}
