#include<stdio.h>
#define MAX 3
int stack[MAX],top=-1,value;
void push()
{
if (top==MAX-1)
{
printf("stack overflow\n");
}
else
{
printf("Enter the value to push:");
scanf("%d",&value);
stack[++top]=value;
printf("%d pushed onto the stack.\n",value);
}
}
void pop()
{
if(top==-1)
{
printf("\nstack underflow\n");
}
else
{
value=stack[top];
top=top-1;
printf("%d popped from the stack.\n",value);
}
}
void display()
{
if (top==-1)
{
printf("stack is empty!\n");
}
else
{
printf("\nstack elements\n");
for(int i=top;i>=0;i--)
{
printf("%d \t",stack[i]);
}
printf("\n");
}
}
int main()
{
int choice;
while(1)
{
printf("\n Menu:\n");
printf("1.push\n");
printf("2.pop\n");
printf("3.display\n");
printf("4.exit\n");
printf("Enter your choice :");
scanf("%d",&choice);
switch (choice)
{
case 1:
	push();
	break;
case 2:
	pop();
	break;
case 3:
	display();
	break;
case 4:
	printf("Exiting..\n");
	return 0;
default :
	printf("Invalid choice! Please try again");
}
}
return 0;
}
	
