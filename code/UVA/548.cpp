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
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm 10001

using namespace std;

int InOrder[mm],PostOrder[mm];

struct Node
{
    int v,l,r;
}node[mm];

int n,cnt,MIN,ANS;

int build(int Il,int Ir,int Pl,int Pr)
{
    //printf("Il=%d Ir=%d Pl=%d Pr=%d:\n",Il,Ir,Pl,Pr);
    int k;

    if (Il==Ir)   return -1;

    for (int i=Il;i<Ir;i++)
    {
        if (InOrder[i]==PostOrder[Pr-1])
        {
            k=i;
            break;
        }
    }

    int t=cnt++;
    node[t].v=InOrder[k];
    node[t].l=build(Il,k,Pl,Pl+k-Il);
    node[t].r=build(k+1,Ir,Pr-Ir+k,Pr-1);
    return t;
}

void dfs(int x,int s)
{
    if (s>MIN)  return ;

    if (node[x].l==-1 && node[x].r==-1)
    {
        if (s+node[x].v<MIN)
        {
            MIN=s+node[x].v;
            ANS=node[x].v;
            return ;
        }
    }


    if (node[x].l!=-1)  dfs(node[x].l,s+node[x].v);
    if (node[x].r!=-1)  dfs(node[x].r,s+node[x].v);

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    char c;
    while (scanf("%d%c",InOrder+0,&c)==2)
    {

        n=1;
        while (true)
        {
            if (c=='\n')    break;
            scanf("%d%c",InOrder+n,&c);
            n++;

        }

        //printf("%d\n",n);

        for (int i=0;i<n;i++)
            scanf("%d%c",PostOrder+i,&c);

        cnt=0;
        build(0,n,0,n);
        MIN=INF;
        dfs(0,0);

        printf("%d\n",ANS);

    }


    return 0;
}
