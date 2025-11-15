#include<stdio.h>
#define MAX 3
int stack [MAX],top=-1,value;
void push()
{
    if(top==MAX-1)
    {
        printf("stack overflow");
    }
    else
    {
        printf("enter the value to push:");
        scanf("%d",&value);
        stack[++top]=value;
        printf("%d pushed on to the stack\n",value);
    }
}
void pop()
{
    if (top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        value=stack[top];
        top=top-1;
        printf("%d popped from the stack",value);
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack empty");
    }
    else
    {
        printf("stack elements:");
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\nMENU");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\nEnter your choice=");
        scanf("%d",&choice);
        switch(choice)
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
            printf(".......exiting.....\n");
            return 0;
            default:
            printf("invalid choice");
        }
    }
    return 0;
}
