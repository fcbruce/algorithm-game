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
#define mm 22222
#define nn 222

using namespace std;

int u[mm],v[mm],w[mm],nex[mm];
int fir[nn];
map<string,int> dict;
int n,m;
int MAX;
int _u,_v,__u;
int inq[nn];
int q[mm];
int d[nn];
int f,r;

void SPFA(int __u)
{
    memset(inq,0,sizeof inq);
    memset(d,0,sizeof d);
    d[__u]=INF;
    f=0;r=-1;
    q[++r]=__u;
    inq[__u]=true;
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (itn e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]<min(w[e],d[u[e]]))
            {
                d[v[e]]=min(w[e],d[u[e]]);
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                }
            }
        }
    }

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    char s1[33],s2[33];
    string str;
    int cnt;
    int T_T=0;
    while (~scanf("%d %d",&n,&m),n||m)
    {
        cnt=-1;
        dict.clear();
        memset(fir,-1,sizeof fir);
        for (int e=0;e<m;e++)
        {
            scanf("%s %s %d",s1,s2,&w[e]);
            str=s1;
            if (dict[str])
                _u=dict[str];
            else
                _u=dict[str]=++cnt;
            str=s2;
            if (dict[str])
                _v=dict[str];
            else
                _v=dict[str]=++cnt;

            u[e]=_u;v[e]=_v;
            nex[e]=fir[_u];
            fir[_u]=e;
            w[e+m]=w[e];
            u[e+m]=_v;v[e+m]=_u;
            nex[e+m]=fir[_v];
            fir[_v]=e+m;
        }

        scanf("%s %s",s1,s2);
        str=s1;_u=dict[str];
        str=s2;_v=dict[str];

        MAX=0;

        SPFA(_u);

        printf("Scenario #%d\n",++T_T);
        printf("%d tons\n\n",d[_v]);
    }




    return 0;
}
