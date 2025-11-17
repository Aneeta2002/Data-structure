#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}*top=NULL;
void push(int element);
void pop();
void display();
int main()
{
	int num,c;
	printf("-------Stack using linked list-------\n");
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.DISPLAY\n");
	printf("4.EXIT\n");
	while(1)
	{
		printf("Enter the choice:\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter the element:\n");
				scanf("%d",&num);
				push(num);break;
			case 2:pop();break;
			case 3:display();break;
			case 4:printf("Exitingg..\n");return 0;
			default:printf("Invalid choice\n");
		}
	}
	return 0;
}
void push(int element)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("Malloc allocation falsed and stack overflow\n");
		return ;
	}
	temp->data=element;
	temp->link=top;
	top=temp;
	printf("%d pushed onto stack\n",element);
}
void pop()
{
	struct node*temp;
	if(top==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	temp=top;
	top=top->link;
	printf("popped element is %d\n",temp->data);
	free(temp);
}
void display()
{
	struct node*temp=top;
	if(temp==NULL)
	{
		printf("stack is empty\n");
		return ;
	}
	printf("stack elememts are:\n");	
	while(temp !=NULL)
	{
		printf("%d--->",temp->data);

		temp=temp->link;
		
	}
	printf("NULL\n");
}	
 
