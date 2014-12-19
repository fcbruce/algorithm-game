#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define itn int
#define maxn 100007<<2
using namespace std;

int setv[maxn];
int gcd[maxn],minv[maxn],maxv[maxn];

int GCD(int x,int y)
{
    if (y==0) return x;
    return GCD(y,x%y);
}

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

inline void pushdown(int k,int l,int r)
{
    if (setv[k]>=0)
    {
        maxv[k*2+1]=maxv[k*2+2]=setv[k*2+1]=setv[k*2+2]=setv[k];
        setv[k]=-1;
    }

//    if (gcd[k]>0)
//    {
//        gcd[k*2+1]=gcd[k*2+2]=gcd[k];
//        int lc=k*2+1,rc=k*2+2;
//        if (gcd[lc]>0 && setv[lc]>gcd[lc])
//            setv[lc]=GCD(setv[lc],gcd[lc]),gcd[lc]=-1;
//        if (gcd[rc]>0 && setv[rc]>gcd[rc])
//            setv[rc]=GCD(setv[rc],gcd[rc]),gcd[rc]=-1;
//        gcd[k]=-1;
//
//    }
}

inline void pushup(int k,int l,int r)
{
    maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        maxv[k]=setv[k]=v;
        return ;
    }

    pushdown(k,l,r);
    update(a,b,v,k*2+1,l,l+r>>1);
    update(a,b,v,k*2+2,l+r>>1,r);
    pushup(k,l,r);
}

void gg(itn a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (maxv[k]<=v)  return ;
    if (a<=l && r<=b)
    {
        if (setv[k]>=0)
        {
            maxv[k]=setv[k]=GCD(v,setv[k]);
            return ;
        }
    }

    pushdown(k,l,r);
    gg(a,b,v,k*2+1,l,l+r>>1);
    gg(a,b,v,k*2+2,l+r>>1,r);
    pushup(k,l,r);
}

//void gg(itn p,int v,itn k,int l,int r)
//{
//    if (r-l==1)
//    {
//        if (setv[k]>v)
//            setv[k]=GCD(setv[k],v);
//
//            return ;
//    }
//
//    itn m=l+r>>1;
//    pushdown(k,l,r);
//    if (p<m)gg(p,v,k*2+1,l,l+r>>1);else gg(p,v,k*2+2,l+r>>1,r);
//
//}

void query(int k,int l,int r)
{
    if (r-l==1)
    {
        printf("%d ",setv[k]);
        return ;
    }

    pushdown(k,l,r);

    query(k*2+1,l,l+r>>1);
    query(k*2+2,l+r>>1,r);
}

void build(int k,int l,int r)
{
    if (r-l==1)
    {
        setv[k]=maxv[k]=ReadInt();
        return ;
    }

    build(k*2+1,l,l+r>>1);
    build(k*2+2,l+r>>1,r);
    pushup(k,l,r);
}

int main()
{
    int T,n,q;
    itn a,b,v,ty;
    scanf("%d",&T);
    while (T--)
    {
       scanf("%d",&n);
//       for (int i=0;i<n;i++)
//       {
//           //scanf("%d",&v);
//           v=ReadInt();
//           update(i,i+1,v,0,0,n);
//       }
        build(0,0,n);

       scanf("%d",&q);
       while (q--)
       {
//           scanf("%d %d %d %d",&ty,&a,&b,&v);
           ty=ReadInt();a=ReadInt();b=ReadInt();v=ReadInt();
           a--;
           if (ty==1)
           {
               update(a,b,v,0,0,n);
           }
           else
           {
//               for (int j=a;j<b;j++)
//                    gg(j,v,0,0,n);
               gg(a,b,v,0,0,n);
           }
       }

       query(0,0,n);
       puts("");
    }
    return 0;
}
