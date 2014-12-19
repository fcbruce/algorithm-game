char p[153];
int i,j,k;
main()
{int n,m;while(~scanf("%d %d",&n,&m)){memset(p,0,sizeof p);for (i=0,j=0,k=1;i<n;){if (k==m){p[j]='B';k=0;i++;}j++;if (j==n*2) j=0;while (p[j]){j++;if(j==n*2) j=0;}k++;}
for(i=1;i<=n*2;i++){putchar(p[i]?'B':'G');if ((i%50)==0)puts("");}if (n*2%50) puts("");puts("");}}
