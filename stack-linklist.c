#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct abc
{
	int a;
	float b;
	struct abc *link;
};
typedef struct abc s;

s* display(s *start)
{
	s *p;
	p=start;
	if(p==NULL)
	{
		printf("Link-list empty!");
	}
	while(p!=NULL)
	{
		printf("\n%d|%f|->%u\n ",p->a,p->b,p->link);
		p=p->link;
	}
	return 0;
}

s* push(s *start, int i, float j)
{
    s *p;
    p=(s*)malloc(sizeof(s));
    p->a=i;
    p->b=j;
    if(start==NULL)
    {
        start=p;
        start->link=NULL;
    }
    else
    {
        p->link=start;
        start=p;
    }
    return start;
}

s* pop(s *start)
{
    s *p;
    p=(s*)malloc(sizeof(s));
    if(start==NULL)
    {
    	printf("Link-List empty::Nothing to display!");
    }
    else
    {
	p = start;
	printf("\n%d|%f|->NULL\n",p->a,p->b);
        start=p->link;        
        p->link=NULL;
    }
    
    return start;
}

int chkfull(s *start)
{
	s *p;
	int cnt=0,flag=0;
	p=(s*)malloc(sizeof(s));
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	if(cnt==10)
	{
		printf("::Stack Full::");
		flag=1;
	}
	else
	{
		printf("::Stack Not Full::");
	}
	return flag;
}

int chkempty(s *start)
{
    s *p;
    int flag=0;
    p=(s*)malloc(sizeof(s));
    if(start==NULL)
    {
    	printf("::Stack empty::");
    	flag=1;
    }
    else
    {
    	printf("::Stack Not empty::");
    }
    return flag; 
}

void main()
{
    s *start;
    int i,ch,flag=0;
    float j;
    start=(s*)malloc(sizeof(s));
    start=NULL;
    while(1)
    {
    	flag=0;
        printf("\n1. PUSH the elements\n2. POP the elements\n3. Check Full\n4. Check Empty\n5. Display Stack\n6. Exit");
        printf("\nEnter your choice:-> ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            	flag=chkfull(start);
            	if(flag==1)
            		break;
                printf("Integer Value: ");
                scanf("%d",&i);
                printf("Float Value: ");
                scanf("%f",&j);
                start = push(start,i,j);
                //display(start);
                break;
            case 2:
            	flag=chkempty(start);
            	if(flag==1)
            		break;
                start = pop(start);
                //display(start);
                break;
            case 3:
            	chkfull(start);
            	break;                
            case 4:
            	chkempty(start);
            	break;
            case 5:
            	display(start);
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong Choice Entered!!\n");
        }
    }
}
