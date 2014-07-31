#include<stdio.h>
#include<stdlib.h>

struct abc
{
	int n;
	float m;
	struct abc *link;
};
typedef struct abc s;

s* display(s *start)
{
	s *a;
	a=start;
	if(a==NULL)
	{
		printf("Link-list empty!");
	}
	while(a!=NULL)
	{
		printf("\n%d|%f|->%u\n ",a->n,a->m,a->link);
		a=a->link;
	}
	return 0;
}

s* insertbeg(s *start, int i, float j)
{
    s *a;
    a=(s*)malloc(sizeof(s));
    a->n=i;
    a->m=j;
    if(start==NULL)
    {
        start=a;
        start->link=NULL;
    }
    else
    {
        a->link=start;
        start=a;
    }
    return start;
}

s* insertend(s *start, int i, float j)
{
    s *a;
    s *p;
    a=(s*)malloc(sizeof(s));
    p=(s*)malloc(sizeof(s));
    a->n=i;
    a->m=j;
    start;
    if(start==NULL)
    {
    	start=a;
    }
    else
    {
	p = start;
	while (p->link!=NULL)
    	{
    		printf("a");
    		p=p->link;	
    	}
        p->link=a;
        p=a;        
        p->link=NULL;
    }
    
    return start;
}

void main()
{
    s *start;
    int i,ch;
    float j;
    start=(s*)malloc(sizeof(s));
    start=NULL;
    while(1)
    {
        printf("\n1. Enter at beginning\n2. Enter at end\n3. Display\n4. Exit");
        printf("\nEnter your choice:-> ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Integer Value: ");
                scanf("%d",&i);
                printf("Float Value: ");
                scanf("%f",&j);
                start = insertbeg(start,i,j);
                display(start);
                break;
            case 2:
                printf("Integer Value: ");
                scanf("%d",&i);
                printf("Float Value: ");
                scanf("%f",&j);
                start = insertend(start,i,j);
                display(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Choice Entered!!\n");
        }
    }
}
