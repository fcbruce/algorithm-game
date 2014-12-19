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
#define mm 1000007
#define nn 1007

using namespace std;

int u[mm],v[mm],w[mm],nex[mm],fir[nn];
int maxe;
int d[nn],q[nn];
bool inq[nn];
int f,r;
int n,m;
int def[nn];//记录兵营到每艘船的时间
int pre[nn];
int rec[nn];//记录每个联通块点燃的最短时间

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

int root(int x)
{
    if (pre[x]==x)  return x;
    return pre[x]=root(pre[x]);
}

inline void intree(int x,int y)
{
    pre[root(x)]=pre[root(y)];
}

inline void read_graph()
{
    int _w;
    maxe=-1;
    memset(fir,-1,(n+1)*sizeof (int));
    for (int i=1;i<=n;i++)
    {
        for (itn j=1;j<=n;j++)
        {
            _w=ReadInt();
            if (_w==-1 || _w==0 && i==j) continue;//坑点，有不同的船距离为0

            intree(i,j);

            maxe++;
            u[maxe]=i;
            v[maxe]=j;
            w[maxe]=_w;
            nex[maxe]=fir[i];
            fir[i]=maxe;
        }
    }
    for (int i=1;i<=n;i++)
    {
        def[i]=ReadInt();
    }
}

inline int SPFA(int _u)
{
    itn MAX=0;
    memset(inq,0,(n+1)*sizeof(int));
    f=0;r=-1;
    memset(d,0x3f,(n+1)*sizeof(int));
    d[_u]=0;
    q[++r]=_u;
    inq[_u]=true;
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (int e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]>d[x]+w[e])
            {
                d[v[e]]=d[x]+w[e];

                if (!inq[v[e]])
                {
                    inq[v[e]]=true;
                    q[++r]=v[e];
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
        if (d[i]!=INF)
            MAX=max(MAX,d[i]);
    return MAX;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++)
            pre[i]=i;
        read_graph();

        int MAX=0;
        memset(rec,0x3f,(n+1)*sizeof(int));
        for (int i=1;i<=n;i++)
        {
            int k=root(i);//一个联通块内的根节点相同
            rec[k]=min(rec[k],SPFA(i)+def[i]);
        }

        for (itn i=1;i<=n;i++)
        {
            MAX=max(MAX,rec[root(i)]);
        }
        printf("%d\n",MAX);

    }


    return 0;
}
