#include<stdio.h>
int main()
{
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf=99999999; 
	scanf("%d %d",&n,&m); //n��ʾ���������m��ʾ�ߵ�����
	//�����1��n�����· 
	for(i=1;i<=n;i++)//��ʼ�� 
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			    e[i][j]=0;
			else
			    e[i][j]=inf;
		}
	 } 
	 
	 for(i=1;i<=m;i++)//�����
	 {
	 	scanf ("%d %d %d",&t1,&t2,&t3);
		 e[t1][t2]=t3; //��ʾ t1 �� t2 ��·��Ϊ t3  
	 } 
	 
	 for(k=1;k<=n;k++) //Floyd-Warshall�㷨 
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
