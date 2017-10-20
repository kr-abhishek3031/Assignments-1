#include<stdio.h>
#include<stdlib.h>
void dfs(int);
int n,k,x,y,visited[100001],indegree[100001],outdegree[100001],flag=1,i;
typedef struct node{
	int data;
	struct node* next;
}node;
node *arr[100001];
int main()
{	
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
//		int n,k,visited[100001],indegree[100001],outdegree[100001],flag=1,i;
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++)
		{
			indegree[i]=0;
			outdegree[i]=0;
			visited[i]=0;
			arr[i]=(node*)malloc(sizeof(node));
			arr[i]->data=0;
			arr[i]->next=NULL;
		}
		for(i=1;i<=k;i++)
		{
			scanf("%d %d",&x,&y);
			indegree[y]++;
			outdegree[x]++;
			node *current=arr[x];
			while(current->next!=NULL)
				current=current->next;
			node *temp=(node*)malloc(sizeof(node));
			temp->data=y;
			temp->next=NULL;
			current->next=temp;
		}
		for(i=1;i<=n;i++)
		{
			if(indegree[i]!=outdegree[i] || outdegree[n]==0 && indegree[n]==0)
			{
				printf("No\n");
				flag=0;
				break;
			}
			//	else if(outdegree[i]==0)
			//		visited[i]=1;
		}
		if(flag==1)
		{
			dfs(1);
			for(i=1;i<=n;i++)
			{
				if(visited[i]==0)
				{
					printf("No\n");
					break;
				}
			}
			if (i>n)
				printf("Yes\n");
		}
	}
	return 0;
}
void dfs(int num)
{
	visited[num]=1;
	node *current=arr[num];
	while(current->next!=NULL)
	{
		if(visited[current->next->data]!=1)
		{
			dfs(current->next->data);
		}
		current=current->next;
	}
}

