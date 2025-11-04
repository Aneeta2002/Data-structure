#include<stdio.h>
# define MAX 3
int queue[MAX];
int rear=-1,front=-1,value;
void enqueue()
{
if ((rear+1)%MAX==front)
{
printf("Queue overflow\n");
}
else
{
printf("Enter the element=");
scanf("%d",&value);
if (front==-1)
{
front=0;
}
rear=(rear+1)%MAX;
queue[rear]=value;
printf("%d added to the queue\n",value);
}
}
void dequeue()
{
if (front==-1)
{
printf("Queue Underflow\n");
}
else
{
printf("%d removed from the queue\n",queue[front]);
if (front==rear)
{
front=rear=-1;
}
else
front=(front+1)%MAX;
}}
void display()
{
if (front==-1)
{
printf("The queue is empty\n");
}
else
{
printf("Queue elements are =");
int i=front;
while(1)
{
printf("%d\t",queue[i]);
if (i==rear)
{
break;
}
i=(i+1)%MAX;
}
printf("\n");
}
}
void search()
{
int found=0;
if (front ==-1)
{
printf("The queue is empty\n");
}
else
{
printf("Enter the element=");
scanf("%d",&value);
int i=front;
while(1)
{
if (queue[i]==value)
{
printf("Element %d is found at the index %d\n",value,i);
found=1;
break;
}
if (i==rear)
break;
i=(i+1)%MAX;
}
if (!found)
{
printf("Element %d not found in queue\n",value);
}
}
}
int main()
{
int choice;
while(1)
{
printf("1.ENQUEUE\n");
printf("2.DEQUEUE\n");
printf("3.DISPLAY\n");
printf("4.SEARCH\n");
printf("5.EXITING\n");
printf("Enter your choice=");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();break;
case 2:dequeue();break;
case 3:display();break;
case 4:search();break;
case 5:printf("Exiting...\n");return 0;
default:printf("Invalid choice\n");
}
}
return 0;
}
