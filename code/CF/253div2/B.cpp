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

char s[500];
int k;
itn l,len,ml;

int main()
{
    #ifndef ONLINE_JUDGE
     //   freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    gets(s);
    len=strlen(s);
    scanf("%d",&k);

    if (len<=k)
    {
        if ((len+k)&1)  printf("%d\n",len+k-1);
        else
            printf("%d\n",len+k);
        return 0;
    }
    ml=len+k;
    for (l=len+k;l;l--)
    {
        if (l&1) continue;
//        printf("l=%d\n",l);
        int n=l>>1;
        for (itn i=0;i<=ml-l;i++)
        {
            bool flag=true;

            for (int j=i;j<i+n;j++)
            {
//                if (j+n<len && i+l<ml)
//                {
//                    printf("j=%d n=%d i=%d\n",j,n,i);
//                    break;
//                }
//                if (j+n<len && i+l>=ml)
//                {
//                    flag=false;
//                    break;
//                }
                if (j+n<len && s[j]!=s[j+n])
                {
//                    printf("j=%d n=%d\n",j,n);
                    flag=false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n",l);
                return 0;
            }

//            int j=i;
//            while (j<i+n && j+n<len && s[j]==s[j+n])   j++;
//            if (j==i+n || j+n==len && i+l<=len+k)
//            {
////                printf("%d %d\n",j,i);
//                printf("%d\n",l);
//                return 0;
//            }
        }
    }



    return 0;
}
