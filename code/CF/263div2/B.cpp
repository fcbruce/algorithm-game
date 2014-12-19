/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-30 09:46:27 
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

#ifdef _WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define maxm 
#define maxn 123456

using namespace std;

char str[maxn];
int __hash[26];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	
	
	int n,k;
	
	scanf( "%d%d",&n,&k);
	
	scanf( "%s",str);
	
	memset(__hash,0,sizeof __hash);
	
	for (int i=0;i<n;i++)
	{
		__hash[str[i]-'A']++;
	}
	
	long long res=0;
	
	while (k)
	{
		int MAX=0,id;
		for (int i=0;i<26;i++)
		{
			if (MAX<__hash[i])
			{
				MAX=__hash[i];
				id=i;
			}
		}
		
		res+=sqr((long long)min(MAX,k));
		__hash[id]-=min(MAX,k);
		k-=min(MAX,k);
		
	}
	
	printf( lld "\n",res);
	
	return 0;
}



