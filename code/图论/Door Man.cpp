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
#define mm

using namespace std;

int deg[22];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    char str[100];
    int door,start,n,u,v;
    while (scanf("%s",str),strcmp(str,"START")==0)
    {
        scanf("%d %d",&start,&n);getchar();
        memset(deg,0,sizeof deg);
        door=0;
        for (int i=0;i<n;i++)
        {
            gets(str);
            char *p=str;
            int l=strlen(str);
            while (p-str<l && sscanf(p,"%d",&u))
            {
//                printf("%d ",u);
                p=p+(int)log10(u)+1+1;
                deg[i]++;
                deg[u]++;
                door++;

            }
//            puts("");
        }

        scanf("%s",str);

        bool flag=true;
        u=-1;v=-1;

        for (int i=0;i<n;i++)
        {
            if (deg[i]&1)
            {
                if (u==-1)
                {
                    u=i;
                }
                else
                {
                    if (v==-1)
                    {
                        v=i;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
            }
        }

        if (flag)
        {
            if (u==-1 && v==-1 && start!=0)
                flag=false;

            if ((u==0 && v==start) || (v==0 && start==u))
            {
                ;
            }
            else
            {
                if (u!=-1 && v!=-1)
                    flag=false;
            }

        }



        if (flag)
            printf("YES %d\n",door);
        else
            puts("NO");

    }


    return 0;
}
