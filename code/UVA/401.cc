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

char s[1111];
int l;
bool pal,mir;

bool ispal()
{
    for (int i=0;i<=l/2;i++)
        if (s[i]!=s[l-i-1])
            return false;

    return true;
}

bool ismir()
{
    for (int i=0;i<=l/2;i++)
    {
        if (s[i]=='A' && s[l-i-1]=='A') continue;
        if (s[i]=='E' && s[l-i-1]=='3') continue;
        if (s[i]=='3' && s[l-i-1]=='E') continue;
        if (s[i]=='H' && s[l-i-1]=='H') continue;
        if (s[i]=='I' && s[l-i-1]=='I') continue;
        if (s[i]=='J' && s[l-i-1]=='L') continue;
        if (s[i]=='L' && s[l-i-1]=='J') continue;
        if (s[i]=='M' && s[l-i-1]=='M') continue;
        if (s[i]=='O' && s[l-i-1]=='O') continue;
        //if (s[i]=='0' && s[l-i-1]=='0') continue;
        //if (s[i]=='0' && s[l-i-1]=='O') continue;
        //if (s[i]=='O' && s[l-i-1]=='0') continue;
        if (s[i]=='S' && s[l-i-1]=='2') continue;
        if (s[i]=='2' && s[l-i-1]=='S') continue;
        if (s[i]=='T' && s[l-i-1]=='T') continue;
        if (s[i]=='U' && s[l-i-1]=='U') continue;
        if (s[i]=='V' && s[l-i-1]=='V') continue;
        if (s[i]=='W' && s[l-i-1]=='W') continue;
        if (s[i]=='X' && s[l-i-1]=='X') continue;
        if (s[i]=='Y' && s[l-i-1]=='Y') continue;
        if (s[i]=='Z' && s[l-i-1]=='5') continue;
        if (s[i]=='5' && s[l-i-1]=='Z') continue;
        if (s[i]=='8' && s[l-i-1]=='8') continue;

       return false;

    }

    return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (~scanf("%s",s))
    {
        l=strlen(s);


        pal=ispal();
  //      for (int i=0;i<l;i++)
    //        if (s[i]=='0')  s[i]='O';
        mir=ismir();

        if (pal && mir) printf("%s -- is a mirrored palindrome.\n",s);
        if (pal && !mir) printf("%s -- is a regular palindrome.\n",s);
        if (!pal && mir) printf("%s -- is a mirrored string.\n",s);
        if (!pal && !mir) printf("%s -- is not a palindrome.\n",s);

        printf("\n");
    }


	return 0;
}
