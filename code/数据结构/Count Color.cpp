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
#define maxn 100007

using namespace std;

int kind[maxn<<2];
int same[maxn<<2];

void pushdown(int k)
{
    if (same[k]!=-1)
    {
        same[k*2+1]=same[k*2+2]=same[k];
        same[k]=-1;
        kind[k*2+1]=kind[k*2+2]=kind[k];
    }
}

void pushup(int k)
{
    kind[k]=kind[k*2+1]|kind[k*2+2];
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        same[k]=v;
        kind[k]=1<<v;
    }
    else
    {
        pushdown(k);
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
        pushup(k);
    }
}

int query(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;
    if (a<=l && r<=b)   return kind[k];
    else
    {
        pushdown(k);
        return query(a,b,k*2+1,l,l+r>>1)|query(a,b,k*2+2,l+r>>1,r);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,t,m,a,b,v;
    char ch;

    scanf("%d %d %d",&n,&t,&m);
    update(0,n,1,0,0,n);
    for (int i=0;i<m;i++)
    {
        scanf("%1s",&ch);
        if (ch=='C')
        {
            scanf("%d %d %d",&a,&b,&v);
            if (a>b)    swap(a,b);
            a--;
            update(a,b,v,0,0,n);
        }
        else
        {
            scanf("%d %d",&a,&b);
            if (a>b)    swap(a,b);
            a--;
            int ans=query(a,b,0,0,n);
            int cnt=0;
            for (int j=t;j>=0;j--)
            {
                if (ans&(1<<j)) cnt++;
            }
            printf("%d\n",cnt);
        }
    }

    return 0;
}
