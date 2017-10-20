#include<stdio.h>
#include<string.h>
int check(char s1[],char s2[])
{	
/*	int i=0,j=0,count=0;
	int l1=strlen(s1);
	int l2=strlen(s2);
	while(j!=l2)
	{
		if(s1[i]==s2[j])
		{
			i++;j++;count++;
		}
		else
		{
			j=0;i++;count=0;
		}
	}*/
	if(strstr(s1,s2)==NULL) return 0;
	else return 1;
}
int main()
{
	char s1[10001],s2[10001],s3[10001];
	int ans,l1,l2,l3,temp1,i,var1,temp2;
	scanf("%s %s",s1,s2);
	l1=strlen(s1);
	l2=strlen(s2);
	temp2=l2;
	temp1=l1;
	ans=check(s1,s2);
	if(check(s1,s2)!=1)
	{
		while(temp2!=0)
		{
			if(s1[temp1-1]==s2[temp2-1])
			{
				temp1--;temp2--;
			}
			else
			{
				temp1=l1;temp2--;
			}
		}
		var1=l1-temp1;
		for(i=0;i<l1;i++)
		{
			s3[i]=s1[i];
		}
		for(i=l1;i<l1+l2;i++)
		{
			s3[i]=s2[i-temp1];
		}
		i=0;
		l3=strlen(s3);
		printf("%d\n",l3);
		printf("%s",s3);
		printf("\n");
	}
	else
	{
		printf("else\n");
		printf("%s",s1);
	}
	printf("\n");
	return 0;
}

