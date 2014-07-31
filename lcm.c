#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,lcm=0,n,m,flag=0;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter m: ");
	scanf("%d",&m);
	if(m>n)
	for(i=1;i<=m;i++)
	{
		lcm=m*i;
		if(lcm%n==0)
		{
			printf("lcm = %d",lcm);
			break;			
		}
	}
	else if(n>m)
	for(i=1;i<=n;i++)
	{
		lcm=n*i;
		if(lcm%m==0)
		{
			printf("lcm = %d",lcm);
			break;			
		}
	}
}
