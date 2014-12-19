#include<cstdio>
#include<cstring>
#define mm 100001
#define MOD 90007


using namespace std;

struct hash
{
    int k,v;
}h[mm];

int a[2];
int cnt=0;

void f(int x)
{
    int ha=x%MOD;
    while (h[ha].k!=-1 && h[ha].k!=x)
    {
        ha++;
        if (ha>=mm)
            ha=0;
    }
    if (h[ha].k==-1)
    {
        h[ha].k=x;
        h[ha].v=0;
    }
    h[ha].v++;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("t.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int tt,n,x;
    scanf ("%d",&tt);

    for (int t=0;t<tt;t++)
    {
        for (int i=0;i<mm;i++)
        {
            h[i].k=h[i].v=-1;
        }
        scanf("%d",&n);

        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            f(x);
        }
        cnt=0;
        for (int i=0;i<mm;i++)
        {
            if (h[i].k!=-1)
            {
                if ((h[i].v%3)==0)  continue;
                if ((h[i].v%3)==2)
                {
                    a[cnt++]=h[i].k;
                    a[cnt++]=h[i].k;
                }
                else
                {
                    a[cnt++]=h[i].k;
                }

            }
        }
        if (a[0]<a[1])
        {
            printf("%d %d\n",a[0],a[1]);
        }
        else
        {
            printf("%d %d\n",a[1],a[0]);
        }
    }

    return 0;
}
