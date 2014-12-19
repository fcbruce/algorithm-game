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
#define mm 100006

using namespace std;

inline int ReadInt()
{
    int flag=0;
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') flag=1;
        ch = getchar();
    }
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
        if(flag) data=-data;
        return data;
}

inline long long ReadInt64()
{
    int flag=0;
    char ch = getchar();
    long long data = 0;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') flag=1;
        ch = getchar();
    }
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
        if(flag) data=-data;
        return data;
}


LL add[mm<<2];
LL sum[mm<<2];

inline void pushup(int k,int l,int r)
{
	sum[k]=0;
	if (r-l>1)	
	{
		sum[k]=sum[k*2+1]+sum[k*2+2];
	}
	sum[k]+=add[k]*(r-l);
}

void update(int a,int b,long long v,int k,int l,int r)
{
    if (b<=l || r<=a) return;

    if (a<=l && r<=b)   add[k]+=v;
    else
    {
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
    }
    
    pushup(k,l,r);
}

LL query(int a,int b,int k,itn l,itn r,LL _add)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b)    return _add*(r-l)+sum[k];

    LL res=0;
    res+=query(a,b,k*2+1,l,l+r>>1,_add+add[k]);
    res+=query(a,b,k*2+2,l+r>>1,r,_add+add[k]);

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,q,a,b,t,m,p;
    LL v;
    while (n=ReadInt())
    {
    	memset(add,0,sizeof add);
    	memset(sum,0,sizeof sum);
//    	scanf( "%d",&t);
		t=ReadInt();
        for (int i=0;i<t;i++)
        {
//            scanf("%d%d%d",&a,&b,&v);
			a=ReadInt();b=ReadInt();v=ReadInt64();
            a--;
            update(a,b,v,0,0,n);
        }
//        scanf( "%d",&m);
		m=ReadInt();
        int cnt=0;
        long  long h;
        while (m--)
        {
//            scanf( "%I64d%d",&h,&p);
			h=ReadInt64();
			p=ReadInt();
            p--;
            long long att=query(p,n,0,0,n,0);
            if (att<h)	cnt++;
            
        }
        
        printf( "%d\n",cnt);
    }


    return 0;
}
