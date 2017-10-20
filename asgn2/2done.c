#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b)
{
	return( *(long long int *)a - *(long long int *)b ) ;
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long int count,n,ans,a[100001],i,flag,r,j;
		ans=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		qsort(a,n,sizeof(long long int),cmpfunc);
	/*	if(a[0]>=n)
			printf("%lld\n",n);
		else{
			for(i=0;i<n;i++)
			{
				if(n-i-1 > a[i+1])
						if(ans < n-i-1)
							ans=n-i-1;
			}*/
		for(i=0;i<n;i++)
		{
			if(a[i]>=n-i)
			{
				if(ans < n - i)
					ans=n-i;
			}
		}
			printf("%lld\n",ans);

	}
	return 0;
}

