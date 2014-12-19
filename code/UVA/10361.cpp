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

char l1[111],l2[111],s[5][111];
int p[5];
int len1,len2;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt;
	scanf("%d",&tt);getchar();

	while (tt--)
    {
        fgets(l1,111,stdin);
        fgets(l2,111,stdin);
        memset(p,-1,sizeof(p));
        p[0]=0;
        int n=1;



        for (int i=0;l1[i]!='\0';i++)
        {
            if(l1[i]=='<' || l1[i]=='>')
            {
                p[n++]=i+1;
                l1[i]='\0';
            }
            if (l1[i]=='\n')
            {
                l1[i]='\0';
                break;
            }
        }

        for (int i=0;i<5;i++)
        {
            strcpy(s[i],&l1[p[i]]);
        }

        printf("%s%s%s%s%s\n",s[0],s[1],s[2],s[3],s[4]);

        for (int i=0;l2[i]!='\0';i++)
        {
            if (l2[i]=='.')
            {
                l2[i]='\0';
                break;
            }
        }
        printf("%s%s%s%s%s\n",l2,s[3],s[2],s[1],s[4]);


    }




	return 0;
}
