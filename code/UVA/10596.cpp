#include<bits/stdc++.h>
#define itn int
#define mm 222

using namespace std;

itn x,y,n,m;
int pre[mm],deg[mm];
bool flag;

void init ()
{
    flag=true;
    memset(deg,0,sizeof deg);
    for (itn i=0;i<mm;i++)
        pre[i]=i;
}

int root(itn x)
{
    if (x==pre[x])  return x;

    return pre[x]=root(pre[x]);
}

int intree(itn x,itn y)
{
    pre[root(x)]=root(y);
}

itn main()
{
    while (~scanf("%d%d",&n,&m))
    {
        init();
        for (itn i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            intree(x,y);
            deg[x]++;
            deg[y]++;
        }
        int stdroot=root(0);
        if (m<=1 || n==0)flag=false;
        for (itn i=0;flag && i<n;i++)
        {
            if (deg[i]!=0 && (stdroot!=root(i) || deg[i]&1))
            {
                flag=false;
                break;
            }

        }
        if (flag)
        {
            printf("Possible\n");
        }
        else
        {
            printf("Not Possible\n");
        }

    }

    return 0;
}
