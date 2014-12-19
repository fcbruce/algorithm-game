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
#define maxm 3333
#define maxn 33

using namespace std;

int deg[maxn],temp[maxn],st[maxn],topo[maxn];
bool vis[maxn];
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
int n,m;

void add_edge(int _u,int _v)
{
    int e=e_max++;
    u[e]=_u;v[e]=_v;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

int topo_sort(int s)
{
    memcpy(temp,deg,sizeof deg);
    int top=-1;
    for (int i=0;i<n;i++)
    {
        if (vis[i] && !temp[i])
        {
            st[++top]=i;
        }
    }
    int cnt=0;
    bool mult=false;
    for (;cnt<s;)
    {
        if (top==-1)    return -1;
        if (top>0)      mult=true;
        int x=topo[cnt]=st[top];cnt++;top--;
//        printf("%d %d\n",cnt,x);
        for (int e=fir[x];~e;e=nex[e])
        {
            temp[v[e]]--;
            if (temp[v[e]]==0)
                st[++top]=v[e];
        }
    }

    if (mult)   return 0;

    return cnt;

}

void write(int tail)
{
    for (int i=0;i<tail;i++)    putchar('A'+topo[i]);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d %d",&n,&m),n||m)
    {
        char str[10];
        int _u,_v,cnt=0,res=0;
        memset(deg,0,sizeof deg);
        memset(vis,0,sizeof vis);
        memset(fir,-1,sizeof fir);
        e_max=0;
        for (int i=0;i<m;i++)
        {
//            printf("i=%d\n",i);
            scanf("%s",str);
            _u=str[0]-'A';
            _v=str[2]-'A';
            add_edge(_u,_v);
            if (!vis[_u]){vis[_u]=true;cnt++;}
            if (!vis[_v]){vis[_v]=true;cnt++;}
            deg[_v]++;

            if (res==0)
            {
//                puts("!");
                int k=topo_sort(cnt);
//                printf("%d\n",k);
                if (k==-1)
                {
                    res=-1;
                    printf("Inconsistency found after %d relations.\n",i+1);
                    continue;
                }
                if (k==n)
                {
                    res=n;
                    printf("Sorted sequence determined after %d relations: ",i+1);
                    write(n);
                    puts(".");
                    continue;
                }
            }
        }

        if (res==0)
        {
            puts("Sorted sequence cannot be determined.");
        }
    }


    return 0;
}
