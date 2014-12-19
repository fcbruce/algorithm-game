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

int n;
char ans[4];
double MAX;
struct point
{
    int x,y;
    char name;
}p[20];

double D(double a,double b,double c,double d)
{
    return a*d-b*c;
}

void check(int x,int y,int z)
{
    point a=p[x],b=p[y],c=p[z];
    double v1x=b.x-a.x,v1y=b.y-a.y;
    double v2x=c.x-a.x,v2y=c.y-a.y;
    double area=abs(v1x*v2y-v1y*v2x);
    double d=D(v1x,v2x,v1y,v2y);

    for (int i=0;i<n;i++)
    {
        if (i==x||i==y||i==z)   continue;
        double v3x=p[i].x-a.x,v3y=p[i].y-a.y;
        double m=D(v3x,v2x,v3y,v2y)/d,n=D(v1x,v3x,v1y,v3y)/d;
        if (m<0 || n<0 || m+n>1)    continue ;
        return ;
    }

    if (MAX<area)
    {
        MAX=area;
        ans[0]=a.name;
        ans[1]=b.name;
        ans[2]=c.name;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%1s%d%d",&p[i].name,&p[i].x,&p[i].y);
        }

       // printf("fuck\n");

        MAX=0;

        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    check(i,j,k);
                }
            }
        }

        sort(ans,ans+3);
        puts(ans);
    }



    return 0;
}
