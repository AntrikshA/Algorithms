//LINK LIST

#include<stdio.h>
#include<conio.h>

struct abc
{
	int info;
	struct abc *link;
};
int data;
struct abc *start,*temp,*newptr;
void ins_beg()
{
	newptr=(struct abc*)malloc(sizeof(struct abc));
	printf("Enter the value:");
	scanf("%d",&data);
	newptr->info=data;
	newptr->link=NULL;
	if(start==NULL)
	{
		start=newptr;
	}
	else
	{
		newptr->link=start;
		start=newptr;
	}
}
void ins_end()
{
	newptr=(struct abc*)malloc(sizeof(struct abc));
	temp=start;
	while(temp->link != NULL)
	{
		temp=temp->link;
	}
	printf("Enter the value:");
	scanf("%d",&data);
	newptr->info=data;
	newptr->link=NULL;
	temp->link=newptr;
}
void ins_mid()
{
	int count=0;
	int pos;
	newptr=(struct abc*)malloc(sizeof(struct abc));
	temp=start;
	while(temp->link!=NULL)
	{
		count++;
		temp=temp->link;
	}
	temp=start;
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos==1)
		ins_beg();
	else if(pos==count+2)
		ins_end();
	else if(pos>0 && pos<=count+1)
	{
		while(pos>2)
		{
			temp=temp->link;
			pos--;
		}
		printf("Enter the value:");
		scanf("%d",&data);
		newptr->info=data;
		newptr->link=temp->link;
		temp->link=newptr;
	}
	else
		printf("Wrong position\n");
}
void display()
{
	newptr=(struct abc*)malloc(sizeof(struct abc));
	temp=start;
	if(start != NULL)
	{
		printf("Link list is :\nStart :");
		while(temp->link != NULL)
		{
			printf("%d->",temp->info);
			temp=temp->link;
		}
		printf("%d",temp->info);
	}
	else
		printf("\nLink List is Empty\n");
	printf("\n");
}

void del_beg()
{
	char ch;
	if(start != NULL)
	{
		fflush(stdin);
		printf("\nAre you sure you want to delete the first node?(y/n):");
		scanf("%c",&ch);
		if(ch=='y' || ch =='Y')
		{
			printf("%d : This node is deleted...",start->info);
			start=start->link;
		}
		else
			printf("Process cancelled...");
	}
	else
		printf("No node to be deleted...\n");
}

void del_end()
{
	char ch;
	if(start != NULL)
	{
		fflush(stdin);
		printf("\nAre you sure you want to delete the last node?(y/n):");
		scanf("%c",&ch);
		if(ch=='y' || ch =='Y')
		{
			temp=start;
			if(temp->link==NULL)
			{
				start=NULL;
			}
			else
			{
				while(temp->link->link != NULL)
				{
					temp=temp->link;
				}
				printf("%d : This node is deleted...",temp->link->info);
				free(temp->link->link);
				temp->link=NULL;
			}

		}
		else
			printf("Process cancelled...");
	}
	else
		printf("No node to be deleted...\n");
}

void del_mid()
{
	int count=0;
	int pos;
	char ch;
	temp=start;
	while(temp->link!=NULL)
	{
		count++;
		temp=temp->link;
	}
	temp=start;
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos==1)
		del_beg();
	else if(pos==count+1)
		del_end();
	else if(pos>0 && pos<count+1)
	{

		while(pos>2)
		{
			temp=temp->link;
			pos--;
		}
		fflush(stdin);
		printf("Confirm Deletion?(y/n):");
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			printf("\n%d: This node is deleted...",temp->link->info);
			temp->link=temp->link->link;
		}
		else
			printf("\nProcess cancelled...");


	}
	else
		printf("Wrong position\n");
}

void swap()
{
	int t1,t2;
	temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	t1=start->info;
	t2=temp->info;
	start->info=t2;
	temp->info=t1;
}

void main()
{

	int ch,data;
	clrscr();
	start=(struct abc*)malloc(sizeof(struct abc));
	start=NULL;
	temp=(struct abc*)malloc(sizeof(struct abc));

	menu:

	clrscr();
	printf("\nMENU\n1.Display\n2.Insert at beginning\n3.Insert at End\n4.Insert in middle\n");
	printf("5.Delete at beginning\n6.Delete at End\n7.Delete in middle\n8.Swap\n9.Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:	clrscr();
		display();
		break;
	case 2:	clrscr();
		ins_beg();
		display();
		break;
	case 3:	clrscr();
		ins_end();
		display();
		break;
	case 4:	clrscr();
		ins_mid();
		display();
		break;
	case 5: clrscr();
		display();
		del_beg();
		display();
		break;
	case 6: clrscr();
		display();
		del_end();
		display();
		break;
	case 7: clrscr();
		display();
		del_mid();
		display();
		break;
	case 8: clrscr();
		display();
		swap();
		display();
		break;
	case 9:	exit();

	}
	printf("\nPress any key to go back to the main menu...");
	getch();
	goto menu;
}
