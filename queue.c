#include<stdio.h>
#define size 3
int queue[size];
int front=-1,rear=-1;
void enqueue()
{
int value;
if(rear==size-1)
{
printf("Queue is overflow\n");
}
else
{
printf("Enter the value to enqueue:");
scanf("%d",&value);
if(front==-1)
front=0;
queue[++rear]=value;
printf("%d added to the queue\n",value);
}}
void dequeue()
{
if (front==-1)
{
printf("Queue is underflow\n");
}
else
{
printf("%d removed from  queue\n",queue[front++]);
if (front>rear)
{
front=rear=-1;
}
}}
void display()
{
if(front==-1||front>rear)
{
printf("Queue is empty\n");
}
else
{
printf("Queue elements:");
for(int i=front;i<=rear;i++)
{
printf("%d\t",queue[i]);
}
printf("\n");
}}
int main()
{
int choice;
while(1)
{
printf("Queue operations\n");
printf("1.Enqueue\n");
printf("2.Dequeue\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
	enqueue();
	break;
case 2:
	dequeue();
	break;
case 3:
	display();
	break;
case 4:
	printf("Exiting...\n");
	return 0;
default:
	printf("Invalid choice");
}
}
return 0;
}
