#include<stdio.h>
#include<string.h>
void func2(char s1[],char s2[], char s3[]);
int check(char s1[],char s2[]);
int func(char s1[],char s2[], char s3[])
{
	char s4[100001],s5[100001];
	int l5;
	func2(s1,s2,s4);
	func2(s4,s3,s5);
	l5=strlen(s5);
	return l5;
}
void func2(char s1[],char s2[], char s3[])
{
	int var1,l2,l1,temp1,temp2,i,l3;
	l2=strlen(s2);
	l1=strlen(s1);
	temp1=l1;temp2=l2;
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
			s3[i]=s2[i-l1];
		}
		i=0;
	}
	else
	{
		for(i=0;i<l1;i++)
			s3[i]=s1[i];
	}
}
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
	if(strstr(s1,s2)== NULL) return 0;
	else return 1;
}

int main()
{
	int min,l[10],i;
	char s1[100001],s2[100001],s3[100001];
	scanf("%s %s %s",s1,s2,s3);
	l[0]=func(s1,s2,s3);
	l[1]=func(s1,s3,s2);
	l[2]=func(s2,s3,s1);
	l[3]=func(s2,s1,s3);
	l[4]=func(s3,s1,s2);
	l[5]=func(s3,s2,s1);
	min=l[0];
	for(i=0;i<6;i++)
	{	
		if(l[i] < min)
			min=l[i];
	}
	printf("%d\n",min);
	return 0;

}


