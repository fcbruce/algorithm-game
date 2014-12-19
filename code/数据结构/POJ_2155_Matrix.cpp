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
#define maxm
#define maxn 1007

using namespace std;

int XOR[maxn<<2][maxn<<2];
int n,m;

//update_1d() 更新一维
//[a,b)表示当前在一维操作的区间(Y方向)，k为节点标号，[l,r)表示节点对应维护的区间(Y方向)，k_2d表示二维对应的节点标号
void update_1d(int a,int b,int k,int l,int r,int k_2d)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        XOR[k_2d][k]^=1;
    }
    else
    {
        update_1d(a,b,k*2+1,l,l+r>>1,k_2d);
        update_1d(a,b,k*2+2,l+r>>1,r,k_2d);
    }
}

//update_2d() 更新二维
//[a,b)表示当前在二维操作的区间(X方向)，[y1,y2)表示将要在一维操作的区间(Y方向)，k为节点标号，[l,r)表示节点对应维护的区间(X方向)
void update_2d(int a,int b,int y1,int y2,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        update_1d(y1,y2,0,0,n,k);
    }
    else
    {
        update_2d(a,b,y1,y2,k*2+1,l,l+r>>1);
        update_2d(a,b,y1,y2,k*2+2,l+r>>1,r);
    }
}

//query_1d() 查询一维
//p表示当前在一维查询的位置(Y方向)，k为节点标号，[l,r)表示节点对应维护的区间(Y方向)，k_2d表示二维对应的节点标号
int query_1d(int p,int k,int l,int r,int k_2d)
{
    if (r-l==1) return XOR[k_2d][k];

    int m=l+r>>1;

    if (p<m)
        return XOR[k_2d][k]^query_1d(p,k*2+1,l,m,k_2d);
    else
        return XOR[k_2d][k]^query_1d(p,k*2+2,m,r,k_2d);
}

//query_2d() 查询二维
//px表示当前在二维查询的位置(X方向)，py表示将要在一维查询的位置(Y方向)，k为节点标号，[l,r)表示节点对应维护的区间(X方向)
int query_2d(int px,int py,int k,int l,int r)
{
    int res=query_1d(py,0,0,n,k);// attention please!

    if (r-l==1) return res;

    int m=l+r>>1;

    if (px<m)
        return res^query_2d(px,py,k*2+1,l,m);
    else
        return res^query_2d(px,py,k*2+2,m,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

	int begintime=clock();

    int T_T;
    scanf("%d",&T_T);


    while (T_T--)
    {

        scanf("%d %d",&n,&m);
        memset(XOR,0,sizeof XOR);

        for (int i=0;i<m;i++)
        {
            char op;
            int x1,x2,y1,y2;

            getchar();
            op=getchar();

            if (op=='C')
            {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1--;y1--;
                update_2d(x1,x2,y1,y2,0,0,n);
            }
            else
            {
                scanf("%d %d",&x1,&y1);
                x1--;y1--;
                printf("%d\n",query_2d(x1,y1,0,0,n));
            }
        }

        if (T_T)    putchar('\n');  //因为这个PE一发
    }

	printf( "%d\n",clock()-begintime);

    return 0;
}
