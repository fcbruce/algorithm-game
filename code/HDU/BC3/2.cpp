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
#define maxn

using namespace std;

map<int,int > SET;
int a[123456],lb[123456],ls[123456],rb[123456],rs[123456],id;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m;

    while (~scanf("%d %d",&n,&m))
    {
        SET.clear();

        for (int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            if (a[i]==m)    id=i;
        }
        lb[id]=ls[id]=rb[id]=rs[id]=0;
        SET[0]=1;

        for (int i=id-1;i>0;i--)
        {
            lb[i]=lb[i+1];
            ls[i]=ls[i+1];
            if (a[i]>m)
                lb[i]++;
            else
                ls[i]++;
//            printf("%d\n",lb[i]-ls[i]);
            SET[lb[i]-ls[i]]++;
        }
//        puts("");

        int cnt=SET[0];
        for (int i=id+1,j=id-1;i<=n;i++)
        {
            rb[i]=rb[i-1];
            rs[i]=rs[i-1];
            if (a[i]>m)
                rb[i]++;
            else
                rs[i]++;

//            printf("%d\n",rs[i]-rb[i]);

                cnt+=SET[rs[i]-rb[i]];
//                printf("cnt=%d\n",cnt);
        }


        printf("%d\n",cnt);


    }



    return 0;
}
