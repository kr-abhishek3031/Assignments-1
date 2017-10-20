#include<stdio.h>
#include<stdlib.h>
int cnt[1001]={0};
int main()
{
	int i,j,n,m,x[1001],y[1001],callx,cally;
	callx=0;cally=0;
	int *arr[100];
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		cnt[x[i]]++;
		cnt[y[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		arr[i]=malloc((cnt[i]+1)*sizeof(int));
		arr[i][0]=1;
	}
	for(i=0;i<m;i++)
	{
		callx=arr[x[i]][0]++;
		arr[x[i]][callx] = y[i];
		cally=arr[y[i]][0]++;
		arr[y[i]][cally] = x[i];
	}
	for(i=1;i<=n;i++)
	{
		printf("list of %d: ",i);
		for(j=1;j<=cnt[i];j++)
		{
			printf("%d ",arr[i][j]);
		}
	printf("\n");
	}
	return 0;
}
















