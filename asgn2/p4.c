#include<stdio.h>
#include<string.h>
void func2(char s1[],char s2[], char s3[]);
int check(char s1[],char s2[]);
long long int min2(long long int,long long int);
long long int min2(long long int a,long long int b)
{
	if (a>b) return b;
	else return a;
}
long long int func(char s1[],char s2[], char s3[])
{
	char s4[200002],s5[300003],s6[300003],s7[200002];
	long long int l4,l7,l5,l6;
	func2(s1,s2,s4);
	func2(s2,s1,s7);
//	printf("in func: %s\n",s4);
//	printf("in func: %s\n",s7);
	l4=strlen(s4);
	l7=strlen(s7);
	if(l4<l7)
	{
		func2(s4,s3,s5);
		func2(s3,s4,s6);
		l5=strlen(s5);
		l6=strlen(s6);
		return min2(l5,l6);
	}
	else 
	{
		func2(s7,s3,s5);
		func2(s3,s7,s6);
		l5=strlen(s5);
		l6=strlen(s6);
		return min2(l6,l5);
	}
}
void func2(char s1[],char s2[], char s3[])
{
	long long int var1,l2,l1,temp1,temp2,i,l3;
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
			s3[i]=s2[i-temp1];
		}
		i=0;
	}
	else
	{
		for(i=0;i<l1;i++)
			s3[i]=s1[i];
	}
//	printf("in func2: %s\n",s3);
}
int check(char s1[],char s2[])
{    
	if(strstr(s1,s2)== NULL) return 0;
	else return 1;
}
int main()
{
	long long int min,l[10],i;
	char s1[100001],s2[100001],s3[100001];
	scanf("%s %s %s",s1,s2,s3);
	l[0]=func(s1,s2,s3);
	l[1]=func(s1,s3,s2);
	l[2]=func(s2,s3,s1);
	//l[3]=func(s2,s1,s3);
//	l[4]=func(s3,s1,s2);
//	l[5]=func(s3,s2,s1);
	min=l[0];
	for(i=0;i<3;i++)
	{	
		if(l[i] < min)
			min=l[i];
	}
	printf("%lld\n",min);
	return 0;

}


