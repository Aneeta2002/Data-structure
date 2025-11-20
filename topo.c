#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n;
int adj[MAX][MAX];
void create_graph();
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
int indegree(int v);
int queue[MAX],front=-1;
int rear=-1;
int main()
{
int i,v,count,topo_order[MAX],indeg[MAX];
create_graph();
for(i=1;i<=n;i++){
indeg[i]=indegree(i);
if(indeg[i]==0)
insert_queue(i);
}
count=0;
while(!isEmpty_queue()&&count<n){
v=delete_queue();
topo_order[count++]=v;
for(i=1;i<=n;i++){
if(adj[v][i]==1){
adj[v][i]=0;
indeg[i]=indeg[i]-1;
if(indeg[i]==0)
insert_queue(i);
}
}
}
if(count<n){
printf("\n No topological ordering possible,graph contains cycle\n");
exit(1);
}
printf("\nVertices in topological order are:\n");
for(i=0;i<count;i++)
printf("\t%d",topo_order[i]);
printf("\n");
return 0;
}
void insert_queue(int vertex){
if(rear==MAX-1){
printf("\nQueue overflow\n");
return;
}
if(front==-1)
front=0;
rear=rear+1;
queue[rear]=vertex;
}
int isEmpty_queue(){
return(front == -1 || front>rear);
}
int delete_queue(){
int del_item;
if(front == -1 || front>rear){
printf("\nQueue Underflow\n");
exit(1);
}
del_item=queue[front];
front=front+1;
return del_item;
}
int indegree(int v){
int i,in_deg=0;
for(i=1;i<=n;i++)
if(adj[i][v]==1)
in_deg++;
return in_deg;
}
void create_graph(){
int i,max_edges,origin,destin;
printf("\nEnter number of vertices:");
scanf("%d",&n);
max_edges=n*(n-1);
for(i=1; i<=max_edges;i++){
printf("\nEnter edge %d(-1 -1 to quit):",i);
scanf("%d %d",&origin,&destin);
if((origin == -1)&&(destin == -1))
break;
if(origin>n||destin>n||origin<1||destin<1){
printf("\nInvalid edge!\n");
i--;
}else{
adj[origin][destin]=1;
}
}
}
