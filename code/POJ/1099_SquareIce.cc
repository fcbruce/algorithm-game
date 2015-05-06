/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 06 May 2015 07:56:57 PM CST
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
#define maxn 

using namespace std;

char zero1[3][4]={"  H","  |","H-O"};
char zero2[3][4]={"H  ","|  ","O-H"};
char zero3[3][4]={"H-O","  |","  H"};
char zero4[3][4]={"O-H","|  ","H  "};
char one[1][6]={"H-O-H"};
char nega[5][4]={"H","|","O","|","H"};

char g[233][233];

int matrix[233][233];

int n;

inline bool le(int i,int j)
{
  if (j==0) return true;
  int k=matrix[i][j-1];
  return k!=1 && k!=3 && k!=5;
}

inline bool up(int i,int j)
{
  if (i==0) return false;
  int k=matrix[i-1][j];
  return k!=-1 && k!=4 && k!=5;
}

inline bool ri(int i,int j)
{
  if (j==n-1) return true;
  int k=matrix[i][j+1];
  return k!=1 && k!=2 && k!=4;
}

inline bool dow(int i,int j)
{
  if (i==n-1) return false;
  int k=matrix[i+1][j];
  return k!=-1 && k!=2 && k!=4;
}

inline int ju(int i,int j)
{
  if (i==0 && j==0) return 3+1;
  if (i==0 && j==n-1) return 4+1;
  if (i==n-1 && j==0) return 1+1;
  if (i==n-1 && j==n-1) return 2+1;

  if (le(i,j) && up(i,j)) return 2;
  if (le(i,j) && dow(i,j)) return 4;
  if (up(i,j) && ri(i,j)) return 3;
  if (ri(i,j) && dow(i,j)) return 5;

  return -1;

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  
  while (scanf("%d",&n),n!=0)
  {
    if (__>0) puts("");
    printf("Case %d:\n\n",++__);

    for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",matrix[i]+j);

    for (int i=0;i<n*4+3;i++) putchar('*');puts("");
    
    memset(g,' ',sizeof g);

    for (int i=0;i<n;i++) for (int j=0;j<n;j++)
    {
      int v=matrix[i][j];

      int ox=i*4+1;
      int oy=j*4+3;

      if (v==0)
      {
        matrix[i][j]=ju(i,j);
        if (ju(i,j)==2) 
        {
          ox-=2;
          oy-=2;
          for (int k=0;k<3;k++) for (int l=0;l<3;l++) g[ox+k][oy+l]=zero1[k][l];
        }
        else if (ju(i,j)==3) 
        {
          ox-=2;
          for (int k=0;k<3;k++) for (int l=0;l<3;l++) g[ox+k][oy+l]=zero2[k][l];
        }
        else if (ju(i,j)==4) 
        {
          oy-=2;
          for (int k=0;k<3;k++) for (int l=0;l<3;l++) g[ox+k][oy+l]=zero3[k][l];
        }
        else if (ju(i,j)==5) 
        {
          for (int k=0;k<3;k++) for (int l=0;l<3;l++) g[ox+k][oy+l]=zero4[k][l];
        }
      }
      else if (v==1)
      {
        oy-=2;
        for (int k=0;k<1;k++) for (int l=0;l<5;l++) g[ox+k][oy+l]=one[k][l];
      }
      else if (v==-1)
      {
        ox-=2;
        for (int k=0;k<5;k++) g[ox+k][oy]=nega[k][0];
      }
    }

    for (int i=0;i<(n-1)*4+1;i++)
    {
      putchar('*');
      for (int j=1;j<n*4+2;j++) putchar(g[i+1][j]);
      putchar('*');
      puts("");
    }



    for (int i=0;i<n*4+3;i++) putchar('*');puts("");


  }



  return 0;
}
