#include<stdio.h>
int main()
{
	int e[10][10],dis[10],book[10];
	int i,j,n,m,t1,t2,t3,u,v ,min;
	int inf=99999999;
	scanf("%d %d",&n,&m);//n表示顶点个数，m表示边的条数
	
	for(i=1;i<=n;i++)//初始化 
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) e[i][j]=0;
			else  e[i][j]=inf;
		}
	 } 
	 for(i=1;i<=m;i++)//输入边 
	 {
	 	scanf("%d %d %d",&t1,&t2,&t3);
	 	e[t1][t2]=t3;//顶点 t1 到顶点 t2 的路程 
	 }
	 
	 for(i=1;i<=n;i++)//源点到各个顶点的初始路程 
	 dis[i]=e[1][i];
	 
	 for(i=1;i<=n;i++)//book数组初始化 
	     book[i]=0;
	 book[1]=1;
	 //核心语句-----------------------
	 for(i=1;i<=n-1;i++)
	 {
	 	min=inf;
	 	for(j=1;j<=n;j++)//找离源点最近的点 
	 	{
	 		if(book[j]==0&&dis[j]<min)
	 		{
	 			min=dis[j];
	 			u=j;
			 }
		 }
		 book[u]=1;//标记已经确定过 
		 for(v=1;v<=n;v++)
		 {
		 	if(e[u][v]<inf)//对所有以点v 为起点的边进行松弛 
		 	{
		 		if(dis[v]>dis[u]+e[u][v])
		 		dis[v]=dis[u]+e[u][v];
			 }
		 }
	 }
	 //------------------------------
	 printf("%d",dis[n]);
	 return 0;
}
