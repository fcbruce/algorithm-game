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

int where[30];
int st[30][30];
char s[10];

void init(int x)
{
    int p=where[x];

    int k=0;
    while (st[p][k]!=x) k++;
    k++;
    while (st[p][k]!=-1)
    {
        st[st[p][k]][0]=st[p][k];
        where[st[p][k]]=st[p][k];
        st[p][k]=-1;
        k++;
    }
}

void MOVE(int x,int y)
{
  //  printf("x=%d y=%d\n",x,y);
    int obj=where[y];
    int k=0;
    while (st[obj][k]!=-1) k++;


    int p=where[x];

    int t=0;

    while (st[p][t]!=x) t++;

    while (st[p][t]!=-1)
    {
        st[obj][k++]=st[p][t];
        where[st[p][t]]=obj;
        st[p][t]=-1;
        t++;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    memset(st,-1,sizeof(st));
    int n,a,b;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        st[i][0]=i;
        where[i]=i;
    }

    while (scanf("%s",s),s[0]!='q')
    {
        if (s[0]=='m')
        {
            scanf("%d%s%d",&a,s,&b);

            if (where[a]==where[b]) continue;

            if (s[1]=='n')
            {
                init(a);init(b);MOVE(a,b);
            }
            else
            {
                init(a);MOVE(a,b);
            }
        }
        else
        {
            scanf("%d %s %d",&a,s,&b);

            if (where[a]==where[b]) continue;

            if (s[1]=='n')
            {
                init(b);MOVE(a,b);
            }
            else
            {
                MOVE(a,b);
            }
        }


    }

    for (int i=0;i<n;i++)
    {
        printf("%d:",i);
        int k=0;
        while (st[i][k]!=-1)    printf(" %d",st[i][k++]);
        puts("");
    }


    return 0;
}
