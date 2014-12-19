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
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

char al[55][55];
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
char word[55];
int n,m,q,l;

bool isbegin(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        bool ok=true;
        int nx,ny;
        for (int j=0;j<l && ok;j++)
        {
            nx=x+dir[i][0]*j;
            ny=y+dir[i][1]*j;
            if (nx<0 || nx>=n || ny<0 || ny>=m) {ok=false;break;}
            if (word[j]!=al[nx][ny])
                ok=false;
        }

        if (ok)
            return ok;
    }

    return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt;

	scanf("%d",&tt);

	while (tt--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%s",al[i]);
            for (int j=0;j<m;j++)
                al[i][j]=tolower(al[i][j]);
        }

        scanf("%d",&q);

        for (int k=0;k<q;k++)
        {
            scanf("%s",word);
            l=strlen(word);
            for (int i=0;i<l;i++)
                word[i]=tolower(word[i]);

            bool f=true;

            for (int i=0;i<n && f;i++)
            {
                for (int j=0;j<m && f;j++)
                {
                    if (isbegin(i,j))
                    {
                        printf("%d %d\n",i+1,j+1);
                        f=false;
                    }
                }
            }

        }

        if (tt)
            puts("");

    }

	return 0;
}
