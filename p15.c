#include <stdio.h> 
#include <time.h> 
void prims(int[10][10],int); 
 int main() 
 { 
 clock_t start,end; 
 double clk; 
 int i,j,n; 
 int cost[10][10]; 
 
 printf("ENTER NO. OF VERTICES\n"); 
 scanf("%d",&n); 
 
 printf("ENTER COST ADJACENCY MATRIX\n"); 
 for(i=0;i<n;i++) 
 for(j=0;j<n;j++) 
 scanf("%d",&cost[i][j]); 
 
 start=clock(); 
 prims(cost,n); 
 end=clock(); 
 
 clk=(double)((end-start)/CLOCKS_PER_SEC); 
 
 printf("TIME REQUIRED IS %f\n",clk); 
 
 return 0; 
 
 } 
 
 void prims(int cost[10][10],int n) 
 { 
 
 int i,j,k,source,u,v,min=9999,sum; 
 int d[10],p[10],visited[10],t[10][2]; 
 
 for(i=0;i<n;i++) //finding source according to min edge 
 for(j=0;j<n;j++) 
 if(cost[i][j]!=0 && cost[i][j]<=min) 
 { 
 min=cost[i][j]; 
 source=i; 
 } 
 
 
 for(j=0;j<n;j++) //finding cost from each source to jth 
vertex 
 { 
 d[j]=cost[source][j]; 
 visited[j]=0; 
 p[j]=source; 
 } 
 
 visited[source]=1; 
 k=0; 
 sum=0; 
 
 for(i=1;i<n;i++) 
 { 
 u=-1;
 min=9999; 
 
 for(j=0;j<n;j++) //finding destination through min edge 
 { 
 if(visited[j]==0) 
 { 
 if(d[j]<=min) 
 { 
 min=d[j]; 
 u=j; 
 } 
 } 
 
 } 
 
 t[k][0]=u; 
 t[k][1]=p[u]; 
 k++; 
 sum+=cost[u][p[u]]; 
 visited[u]=1; 
 
 for(v=0;v<n;v++) //where to next? 
 { 
 if(cost[u][v]<d[v] && visited[v]==0) 
 { 
 d[v]=cost[u][v]; 
 p[v]=u; 
 } 
 } 
 } 
 
 if(sum>=9999) 
 printf("NO SPANNING TREE EXISTS\n"); 
 else 
 { 
 printf("SPANNING TREE\n"); 
 
 for(i=0;i<n-1;i++) 
 printf("%d --> %d\n",t[i][0],t[i][1]); 
 
 printf("COST OF SPANNING TREE IS %d",sum); 
 
 } 
 
 
 } 
