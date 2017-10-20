#include<stdio.h>
#define m 1000000007
long long int sum[100001],final[100001];
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long int n,k,i,j,a[100001],ans=0,var1,var2,var3,var4,var5,var6;
		scanf("%lld %lld",&n,&k);
		for(i=0;i<100001;i++)
		{
			a[i]=0;
			sum[i]=0;
			final[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(i>0)
				sum[i]=(a[i]+sum[i-1])%k;
			else
				sum[i]=a[i]%k;
		}
		//for(i=0;i<n;i++)
		//	sum[i]=sum[i]%k;
		for(i=0;i<n;i++)
			final[sum[i]]++;
		final[0]++;
		for(i=0;i<k;i++)
		{
			if(final[i]%2==0)
			{
				ans=ans+(((final[i]-1)%m)*(((final[i])/2)%m)%m);
			}
			else 
			{
				ans=ans+((final[i]%m)*(((final[i]-1)/2)%m)%m);  
			}
		}
/*
		for(i=0;i<k;i++)
		{
			var1=final[i]%m;
			var2=final[i]-1;
			var3=var2%m;
			var4=var1*var3;
			var5=var4%m;
			var6=var5/2;
			ans=ans+((((final[i]%m)*(final[i]-1)%m))%m)/2;
		}*/
		printf("%lld\n",ans%m);
	}
	return 0;
}

