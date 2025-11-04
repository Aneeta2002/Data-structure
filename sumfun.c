#include<stdio.h>
int sum1(int a[10],int n)
{
int i,sum=0;
for(i=0;i<n;i++)
{
sum=sum+a[i];
}
return sum;
}
void main()
{
int i,n,a[10];
printf("Enter the array:");
scanf("%d",&n);
printf("Enter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
int result=sum1(a,n);
printf("Natural numbers are:%d",result);
}

