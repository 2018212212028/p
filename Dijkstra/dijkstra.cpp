#include<stdio.h>
int main()
{
	int e[10][10],dis[10],book[10];
	int i,j,n,m,t1,t2,t3,u,v ,min;
	int inf=99999999;
	scanf("%d %d",&n,&m);//n��ʾ���������m��ʾ�ߵ�����
	
	for(i=1;i<=n;i++)//��ʼ�� 
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) e[i][j]=0;
			else  e[i][j]=inf;
		}
	 } 
	 for(i=1;i<=m;i++)//����� 
	 {
	 	scanf("%d %d %d",&t1,&t2,&t3);
	 	e[t1][t2]=t3;//���� t1 ������ t2 ��·�� 
	 }
	 
	 for(i=1;i<=n;i++)//Դ�㵽��������ĳ�ʼ·�� 
	 dis[i]=e[1][i];
	 
	 for(i=1;i<=n;i++)//book�����ʼ�� 
	     book[i]=0;
	 book[1]=1;
	 //�������-----------------------
	 for(i=1;i<=n-1;i++)
	 {
	 	min=inf;
	 	for(j=1;j<=n;j++)//����Դ������ĵ� 
	 	{
	 		if(book[j]==0&&dis[j]<min)
	 		{
	 			min=dis[j];
	 			u=j;
			 }
		 }
		 book[u]=1;//����Ѿ�ȷ���� 
		 for(v=1;v<=n;v++)
		 {
		 	if(e[u][v]<inf)//�������Ե�v Ϊ���ı߽����ɳ� 
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
