/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define maxm 
#define maxn 

using namespace std;

char t[4];

struct DoubleLetter
{
	string ableToSolve(string S)
	{
		char s[100];
		strcpy(s,S.c_str());
		while (strlen(s))
		{
			char *p=NULL;
			bool f=false;
			for (int i=0;i<26;i++)
			{
				t[0]=t[1]='a'+i;
				t[2]='\0';
				p=strstr(s,t);
				if (p!=NULL)
				{
					f=true;
//					printf("%d\n",p-s);
//					puts(p);
//					puts(p+2);
//					strcpy(p,p+2);
					for (;*(p+2);p++)
						*p=*(p+2);
					*p='\0';
					puts( s);
				}
			}
			if (f)	break;
		}
		if (strlen(s)==0)	return "possible";
		else	return "impossible";
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	DoubleLetter ff;
	ff.ableToSolve("aabccb");
	
	
	return 0;
}



