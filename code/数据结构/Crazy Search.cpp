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
#define mm 16000007

using namespace std;

int n,nc;
char s[mm];
int _hash[mm];
int ind[30];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d%d",&n,&nc))
    {
        scanf("%s",s);
        memset(_hash,0,sizeof (_hash));
        memset(ind,-1,sizeof ind);
        int l=strlen(s);
        for (int i=0,k=0;k<nc;i++)
        {
            if (ind[s[i]-'a']==-1)  ind[s[i]-'a']=k++;
        }
        puts("yes");
        int ans=0;
        for  (itn i=0;i<l-n+1;i++)
        {
            int v=0;
            for (int j=0;j<n;j++)
            {
                v=v*nc+ind[s[i+j]-'a'];
//                if (v>mm)
//            {
//                puts("error");
//                return -1;
//            }
            }
            if (_hash[v]==0)
            {
                ans++;
                _hash[v]=1;
            }
        }
        printf("%d\n",ans);
    }


    return 0;
}
