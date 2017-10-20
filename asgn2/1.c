#include<stdio.h>
#include<stdlib.h>
int visited[100001];
int *arr[100001];
int i,j,n,m,visited[100001],x,y,callx,cally,ans,indegree[100001],outdegree[100001],check,flag=1;
int cnt[100001]={0};
int dfs(int num)
{
	//visited[num]=1;
	for(i=1;i<=cnt[num];i++)
	{
		if(visited[num]!=0)
		{
			if(visited[n]==1) return 1;
		}
		else
		{
			visited[num]=1;
			dfs(arr[num][i]);
		}
	}
	if(visited[n]==0) return 0;
}
int main()
{
//	int *arr[100001];
//	int i,j,n,m,x[100001],y[100001],callx,cally,ans,indegree[100001],outdegree[100001],check,flag=1;
	callx=0;cally=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		cnt[x]++;
		indegree[y]++;
		outdegree[x]++;
	}
	for(i=1;i<=m;i++)
	{
		arr[i]=malloc((cnt[i]+1)*sizeof(int));
		arr[i][0]=1;
	}
	for(i=0;i<m;i++)
	{
		callx=arr[x][0]++;
		arr[x][callx] = y;
		//		printf("indegree of %d is: %d\n",i+1,indegree[i+1]);
		//		printf("outdegree of %d is: %d\n",i+1,outdegree[i+1]);
	}
	//	for(i=1;i<=n;i++)
	//	{
	//		printf("list of %d: ",i);
	//		for(j=1;j<=cnt[i];j++)
	//		{
	//			printf("%d ",arr[i][j]);
	//		}
	//	printf("\n");
	//	}
	for(i=1;i<n;i++)
	{
		if(indegree[i]!=outdegree[i])
		{
			flag=0;
			break;
		}
	}
	check=dfs(1);
	if(check==1 && flag==1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}




