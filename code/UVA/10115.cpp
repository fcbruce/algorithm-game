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

char bef[20][300],aft[20][300];
char str[300],temp[300];
char *p=NULL;
int l,n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (scanf("%d",&n))
    {
        if (n==0)
            break;

        getchar();

        for (int i=0;i<n;i++)
        {
            fgets(bef[i],300,stdin);
            fgets(aft[i],300,stdin);

            for (int j=0;bef[i][j];j++)
                if (bef[i][j]=='\n')
                {
                    bef[i][j]='\0';
                    break;
                }
            for (int j=0;aft[i][j];j++)
                if (aft[i][j]=='\n')
                {
                    aft[i][j]='\0';
                    break;
                }
        }

        fgets(str,300,stdin);
        for (int i=0;str[i];i++)
            if (str[i]=='\n')
            {
                str[i]='\0';
                break;
            }

        for (int i=0;i<n;i++)
        {
            while (p=strstr(str,bef[i]),p!=NULL)
            {
                l=strlen(bef[i]);
                strcpy(temp,aft[i]);
                strcat(temp,p+l);
                strcpy(p,temp);
            }
        }

        puts(str);


    }


	return 0;
}
