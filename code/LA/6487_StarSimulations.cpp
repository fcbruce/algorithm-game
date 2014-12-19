#include <bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define eps 1e-8
#define maxn 100007

using namespace std;

struct _point
{
    int x,y,z;
    double dis;
    bool operator < (const _point &p)const
    {
        return dis<p.dis;
    }
}p[maxn];

inline bool judge(const _point &p1,const _point &p2,double K)
{
    return sqrt(sqr((double)(p1.x-p2.x))+sqr((double)(p1.y-p2.y))+sqr((double)(p1.z-p2.z)))<K-eps;
}

inline int ReadInt()
{
    int flag=0;
    char ch=getchar();
    int data=0;
    while (ch<'0' || ch>'9')
    {
        if (ch=='-') flag=1;
        ch=getchar();
    }
    do
    {
        data=data*10+ch-'0';
        ch=getchar();
    }while (ch>='0' && ch<='9');

    if (flag) data=-data;

    return data;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t.txt","r",stdin);
#endif
    int n,k;

    while (1)
    {
        n=ReadInt();
        k=ReadInt();
        if (n==0 ||k==0) break;
        double K=k;
        for (int i=0,x,y,z;i<n;i++)
        {
            x=ReadInt();
            y=ReadInt();
            z=ReadInt();
            p[i]=(_point){x,y,z,sqrt(sqr((double)x)+sqr((double)y)+sqr((double)z))};
        }

        sort(p,p+n);

        int cnt=0;
        for (int i=0,j=0;i<n;i++)
        {
            while (j<i && p[j].dis+K<p[i].dis-eps) j++;

            for (int k=j;k<i;k++)
                if (judge(p[i],p[k],K)) cnt++;
        }

        printf("%d\n",cnt);
    }

    return 0;
}
