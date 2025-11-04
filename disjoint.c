#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int parent[MAX];
int rank[MAX];
int countRoot;
int head[MAX];
int tail1[MAX],tail2[MAX];
struct node{
	struct node*rep;
	struct node*next;
	int data;
}*head[50],*tails[50]
static int countRoot=0;
void makeSet(int x){
struct node*newNode=(struct node*)malloc(sizeof(struct node));
newNode->rep=newNode;
newNode->next=NULL;
newNode->data=x;
head[countRoot]=newNode;
tail[countRoot++]=newNode;
}
struct node*find(int a){
int i;
struct node*temp;
for(i=0;i<countRoot;i++){
temp=head[i];
while(temp!=NULL){
if(temp->data==a)
return temp->rep;
temp=temp->next;
}
}
return NULL;
}
void unionSets(int a, int b){
int i,pos,flag=0,j;
struct node*tail2;
struct node*rep1=find(a);
struct node*rep2=find(b);
if(rep1==NULL||rep2==NULL){
printf("\nElement not present in the DS\n");
return;
}
if(rep1 !=rep2){
for(j=0;j<countRoot;j++){
if (head[j]==rep2){
pos=j;
flag=1;
countRoot-=1;
tail2=tail[j];
for(i=pos;i<countRoot;i++){
head[i]=heads[i+1];
tail[i]=tails[i+1];
}
}
if (flag==1)
break;
}
for (j=0;j<countRoot;j++){
if (heads[j]==rep1){
tails[j]->next=rep2;
tails[j]=tail2;
break;
}
}
while(rep2!=NULL){
rep2->rep=rep1;
rep2=rep2->next;
}
}
}
int search(int x){
int i;
struct node*temp;
for(i=0;i<countRoot;i++){
temp=head[i];
if (head[i]->data==x)
return 1;
while(temp!=NULL){
if(temp->data==x)
return 1;
temp=temp->next;
}
}
return 0;
}
void main(){
int choice,x,i,j,y;
struct node*rep;
do{
printf("\n....MENU.....\n");
printf("1.Make Set\n");
printf("2.Display set representatives\n");
printf("3.Union\n");
printf("4.Find Set\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter new element:\n");
scanf("%d",&x);
if(search(x)==1)
printf("\n Element already present in the disjoint set DS\n");
else{
makeSet(x);
}
break;
case 2:
printf("\nSet representatives:\n");
for(i=0;i<countRoot;i++)
printf("%d",head[i]->data);
printf("\n");
break;
case 3:
printf("\nEnter the first element:");
scanf("%d",&x);
printf("\nEnter the second element:");
scanf("%d",&y);
unionSet(x,y);
break;
case 4:
printf("\nEnter the element:");
scanf("%d",&x);
rep=find(x);
if(rep==NULL)
printf("\nElement not present in the DS\n");
else
printf("\nThe representative of %d is %d\n",x,rep->data);
break;
case 5:
exit(0);
default:
printf("\nWrong choice\n");
break;
}
}while(1);
}
