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
#define mm 50005

using namespace std;

int lm[mm<<2],rm[mm<<2];
int st[mm],top;
int n,m;

void pushup(int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;
    if (lm[lc]==m-l)    lm[k]=lm[lc]+lm[rc];    else    lm[k]=lm[lc];
    if (rm[rc]==r-m)    rm[k]=rm[rc]+rm[lc];    else    rm[k]=rm[rc];
}

void update(int x,int v,int k,int l ,int r)
{
    if (r-l==1)
    {
        lm[k]=rm[k]=v;
    }
    else
    {
        int m=l+r>>1;
        if (x<m)    update(x,v,k*2+1,l,m);  else    update(x,v,k*2+2,m,r);
        pushup(k,l,r);
    }

}

int query(int x,int k,int l,int r)
{
    if (r-l==1) return lm[k];
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;
    if (x>=m-rm[lc] && x<m+lm[rc])   return lm[rc]+rm[lc];
    if (x<l+lm[lc]) return lm[lc];
    if (x>=r-rm[rc]) return rm[rc];

    if (x<m)    return query(x,lc,l,m); else    return query(x,rc,m,r);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int x;

    while (scanf("%d %d",&n,&m)==2)
    {
        for (int i=0;i<n;i++)
            update(i,1,0,0,n);

        top=-1;

        char op;
        while (m--)
        {
            scanf("%1s",&op);
            if (op=='D')
            {
                scanf("%d",&x);
                x--;
                st[++top]=x;
                update(x,0,0,0,n);
                continue;
            }

            if (op=='R')
            {
                x=st[top--];
                update(x,1,0,0,n);
                continue;
            }

            if (op=='Q')
            {
                scanf("%d",&x);
                x--;
                printf("%d\n",query(x,0,0,n));
            }

        }
    }

    return 0;
}
