#include<stdio.h>
#include<string.h>
int str[26][100001];
int main()
{
	char s[100001],str2[100001];
	int n,i,j,count[26]={0}, point[26]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		str2[i]=s[0];
		count[s[0]-96]++;
	}
	for(i=1;i<=n;i++)
	{
		str[str2[i]-96][point[str2[i]-97]++]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<count[i];j++)
		{
			printf("%d ",str[i][j]);
		}
		printf("\n");
	}
return 0;
}
	

