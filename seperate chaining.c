#include<stdio.h>
#include<stdlib.h>
#define size 10
void insert();
void search();
void display();
struct node
{
	int data;
	struct node *next;
};
int *a[size]={NULL};
int main()
{
	int opt;
	while(1)
	{
		printf("\n enter 1 for insert");
		printf("\n enter 2 for search");
		printf("\n enter 3 for display");
		printf("\n enter other option for exit");
		printf("\n enter ur choice");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:insert();
			break;
			case 2:search();
			break;
			case 3:display();
			break;
			default:exit(1);
		}
	}
}
void insert()
{
	struct node *newnode,*ptr;
	int key,i;
	printf("\n enter key to be insert into the hash table");
	scanf("%d",&key);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=NULL;
	i=key%size;
	if(a[i]==NULL)
	{
		a[i]=newnode;
	}
	else
	{
		ptr=a[i];
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
void search()
{
	struct node *ptr;
	int key,i,search=0;
	printf("\n enter key to search");
	scanf("%d",&key);
	i=key%size;
	ptr=a[i];
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			search=1;
			break;
		}
		ptr=ptr->next;
	}
	if(search==1)
	{
		printf("\n key is found");
	}
	else
	{
		printf("\n key is not found");
	}
}
void display()
{
	struct node *ptr;
	int i;
	for(i=0;i<size;i++)
	{
		ptr=a[i];
		printf("\n a[%d]-> ",i);
		while(ptr!=NULL)
		{
			printf("%d-> ",ptr->data);
			ptr=ptr->next;
		}
		printf("NULL\n");
	}
}