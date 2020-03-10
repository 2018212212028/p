#include<stdio.h>
int main()
{
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf=99999999; 
	scanf("%d %d",&n,&m); //n表示顶点个数，m表示边的条数
	//输出从1到n的最短路 
	for(i=1;i<=n;i++)//初始化 
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			    e[i][j]=0;
			else
			    e[i][j]=inf;
		}
	 } 
	 
	 for(i=1;i<=m;i++)//输入边
	 {
	 	scanf ("%d %d %d",&t1,&t2,&t3);
		 e[t1][t2]=t3; //表示 t1 到 t2 的路程为 t3  
	 } 
	 
	 for(k=1;k<=n;k++) //Floyd-Warshall算法 
     {
	    for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=n;j++)
	    	{
	    		if(e[i][j]>e[i][k]+e[k][j])
	    		{
	    			e[i][j]=e[i][k]+e[k][j];
	    		 } 
	    	}
	    }
	 } 
	printf("%d\n",e[1][n]); 
	 return 0;
}
