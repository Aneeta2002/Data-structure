#include<stdio.h>
#include<stdlib.h>
#define N 10
int main() 
{
int i, j, k = 0, t;
int u[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int a[N], b[N];
int sa[N], sb[N], us[N], cs[N], ds[N], c[N], d[N];
int setASize;
printf("Enter the size of Set A: ");
scanf("%d", &setASize);
printf("Enter the elements of Set A (space-separated): ");
for(i = 0; i < setASize; i++) 
{
scanf("%d", &a[i]);
}
int setBSize;
printf("Enter the size of Set B: ");
scanf("%d", &setBSize);
printf("Enter the elements of Set B (space-separated): ");
for(i = 0; i < setBSize; i++) 
{
scanf("%d", &b[i]);
}
for (i = 0; i < N; i++) 
{
us[i] = 1;
}
printf("\nUniversal Set bitstring:\n");
for (i = 0; i < N; i++) 
{
printf("%d\t", us[i]);
}
for (i = 0; i < N; i++) 
{
t = 0;
for (j = 0; j < setASize; j++) 
{
if (a[j] == u[i]) 
{
t = 1;
break;
}
}
sa[i] = t;
}
printf("\nSet A bitstring:\n");
for (i = 0; i < N; i++) 
{
printf("%d\t", sa[i]);
}
for (i = 0; i < N; i++) 
{
t = 0;
for (j = 0; j < setBSize; j++) 
{
if (b[j] == u[i]) 
{
t = 1;
break;
}
}
sb[i] = t;
}
printf("\nSet B bitstring:\n");
for (i = 0; i < N; i++) 
{
printf("%d\t", sb[i]);
}
printf("\n");
for (i = 0; i < N; i++) 
{
cs[i] = (sa[i] || sb[i]);
}
printf("\nUnion bitstring:\n");
for (i = 0; i < N; i++) 
{
printf("%d\t", cs[i]);
}
printf("\nUnion number set:\n");
for (i = 0; i < N; i++) 
{
if (cs[i] == 1) 
{
c[k] = u[i];
printf("%d\t", c[k]);
k++;
}
}
printf("\n");
for (i = 0; i < N; i++) 
{
ds[i] = (sa[i] && sb[i]);
}
printf("\nIntersection bitstring:\n");
for (i = 0; i < N; i++) 
{
printf("%d\t", ds[i]);
}
printf("\nIntersection number set:\n");
k = 0;
for (i = 0; i < N; i++) 
{
if (ds[i] == 1) 
{
d[k] = u[i];
printf("%d\t", d[k]);
k++;
}
}
printf("\n");
return 0;
}
