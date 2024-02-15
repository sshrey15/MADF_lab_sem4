#include <stdio.h>
#include <stdlib.h>


#define N 10000

int cost[8][8] = {
    {0, 5, 2, N, N, N, N, N},
    {5, 0, 3, 2, 1, N, N, N},
    {2, 3, 0, N, 4, N, N, 3},
    {N, 2, N, 0, 3, 2, N, N},
    {N, 1, 4, 2, 0, 1, 3, 2},
    {N, N, N, 2, 1, 0, 4, N},
    {N, N, N, N, 3, 4, 0, N},
    {N, N, 3, N, 2, N, N, 0}
};

void show(int arr[],int n){
for(int i=0;i<n;i++)printf("%2d",arr[i]+1);printf("\n");}

void display(int arr[],int n){
for(int i=0;i<n;i++){
	if(cost[i][arr[i]]==N)printf("N");
	else printf("%2d",cost[i][arr[i]]);
}
}

int prim(int t[][2],int n){
int low=N;
int k,l,mincost=0;
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(cost[i][j]<low&&cost[i][j]!=0){
				low=cost[i][j];
				k=i;
				l=j;
			}
		}
	}
t[0][0]=k;
t[0][1]=l;
mincost=cost[k][l];
printf("k:%d l:%d\n",k+1,l+1);
int near[n];//declare a matrix near to store the 'near' information

for(int i=0;i<n;i++){//start of a for loop

if(i==k||i==l)//here we check if value of near is j or k. If yes, then put that particular location as -1
near[i]=-1;

else{
if(cost[k][i]<cost[l][i])
near[i]=k;

else near[i]=l;

}
}//end of for loop
printf("near:");show(near,8);
printf("\n");

for(int i=1;i<n-1;i++){
int min=N,r;
for(int j=0;j<n;j++){
if(near[j]!=-1 && cost[j][near[j]]<min){
min=cost[j][near[j]];
 r=j;}
 }
 t[i][0]=r; t[i][1]=near[r];mincost=mincost+cost[r][near[r]];
 printf("near:");show(near,8);
 printf("\n");
 for(int j=0;j<n;j++){
 if(near[j]==-1||j==r)near[j]=-1;
 else{
 if((cost[j][r]<cost[j][near[j]]))near[j]=r;
 }
 }}
 return mincost;
 }
 
 int main(){
 int t[7][2];
int mincost=prim(t,8);
 for(int i=0;i<7;i++)printf("%d %d\n",t[i][0]+1,t[i][1]+1);
 printf("\n mincost:%d",mincost);
 return 0;
 }

