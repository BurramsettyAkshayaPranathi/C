#include<stdio.h>

struct node {


int data;

int priority;

struct node *next;
}*start=NULL;

int main()

{ 
while (1) {

int ch;

printf("\nenter I for enqueue \n 2 for dequeue\n 3 for display\n");

scanf ("%d", &ch);

switch(ch)
{

case 1: enqueue();

break;

case 2:  dequeue();
break;

case 3: display();

break;

default:
   exit(1);
}
}
}
void enqueue() {
    struct node* newnode;
    struct node* ptr;
    int newpriority;

    
    newnode = (struct node*)malloc(sizeof(struct node));
   
    printf("Enter data:");
    scanf("%d", &newnode->data);

    printf("Enter priority");
    scanf("%d", &newpriority);
    
    newnode->priority = newpriority;
    newnode->next = NULL;

   
    if (start == NULL || start->priority>newpriority) {
        newnode->next = start;
        start = newnode;
    } else {
       
        ptr = start;
        while (ptr->next != NULL && ptr->next->priority <= newpriority) {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}
void dequeue() {
    if (start == NULL) {
        printf("Queue is empty\n");
        
    }
else
{

    struct node* ptr = start;
    printf(" %d is deleted ",start->data);
    
    start = start->next;

    free(ptr);

}
}
void display()
{
	if(start==NULL)
	printf("\n queue empty");
	struct node *ptr=start;
	while(ptr!=NULL)

{
	printf("%d->%d  ",ptr->priority,ptr->data);
	ptr=ptr->next;
}
}


