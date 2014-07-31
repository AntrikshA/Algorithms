#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,hcf=0,n,m;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter m: ");
	scanf("%d",&m);
	if(m>n)
	for(i=1;i<=n;i++)
	{
		if(n%i==0 && m%i==0)
		{
			hcf=i;
		}
	}
	else if(n>m)
	for(i=1;i<=m;i++)
	{
		if(n%i==0 && m%i==0)
		{
			hcf=i;
		}
	}
	printf("hcf = %d",hcf);
}
