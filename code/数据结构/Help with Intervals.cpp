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
#define maxn 65536

using namespace std;

int setv[maxn<<3],XOR[maxn<<3];//setv[k]为-1表示区间内值不同，不能立刻进行xor运算
int pos[maxn<<1];

void pushxor(int k)
{
    if (setv[k]!=-1)
        setv[k]^=1;
    else
        XOR[k]^=1;
}
void pushdown(int k)
{
    if (setv[k]!=-1)
    {
        setv[k*2+1]=setv[k*2+2]=setv[k];
        setv[k]=-1;
        XOR[k*2+1]=XOR[k*2+2]=0;
    }

    if (XOR[k])
    {
        pushxor(k*2+1);pushxor(k*2+2);
        XOR[k]=0;
    }
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return;

    if (a<=l && r<=b)
    {
        setv[k]=v;
        XOR[k]=0;
    }
    else
    {
        pushdown(k);
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
    }
}

void change(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return;
    if (a<=l && r<=b)
    {
        if (setv[k]!=-1)
            setv[k]^=1;
        else
        {
            XOR[k]^=1;
        }
    }
    else
    {
        pushdown(k);
        change(a,b,k*2+1,l,l+r>>1);
        change(a,b,k*2+2,l+r>>1,r);
    }
}

void query(int k,int l,int r)
{
    if (r-l==1)
    {
        pos[l]=setv[k]^XOR[k];

        return ;
    }
    pushdown(k);
    query(k*2+1,l,l+r>>1);
    query(k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    itn n=65536<<1;
    char op,ll,rr;
    int a,b;

    while (~scanf("%1s ",&op))
    {
        scanf("%c%d,%d%c",&ll,&a,&b,&rr);
        a<<=1;b<<=1;
        if (ll=='(')    a++;
        if (rr==')')    b--;

        if (op=='U')    update(a,b+1,1,0,0,n);
        if (op=='I')
        {
            update(0,a,0,0,0,n);
            update(b+1,n,0,0,0,n);
        }
        if (op=='D')
        {
            update(a,b+1,0,0,0,n);
        }
        if (op=='C')
        {
            update(0,a,0,0,0,n);
            update(b+1,n,0,0,0,n);
            change(a,b+1,0,0,n);
        }
        if (op=='S')
        {
            change(a,b+1,0,0,n);
        }
    }


    query(0,0,n);
    int L,R;
    R=L=-1;
    bool flag=false;

    for (int i=0;i<n;i++)
    {
        if (pos[i])
        {
            R=L=i;
            while (pos[R+1])    R++;
        }
        if (R!=-1)
        {
            if (flag)   putchar(' ');
            printf("%c%d,%d%c",L&1?'(':'[',L>>1,R+1>>1,R&1?')':']');
            flag=true;
            i=R;
            L=R=-1;
        }

    }

    if (!flag)  printf("empty set");

    puts("");

    return 0;
}
