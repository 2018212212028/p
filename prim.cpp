#include<iostream>//Prim算法的简单实现(最小生成树的最小生成路径)
#include<cstdio>
#include<cstring>
#define inf (0x3f3f3f3f)
using namespace std;
const int maxn = 100 + 15;
int Grape[maxn][maxn];// u ~ v节点之间边的权值  (-1表示边不存在)
int d[maxn];//每个节点到Tree的最短距离
int p[maxn];//每个节点的父节点
int n;//n个节点
bool vis[maxn];//判断每个节点是否被访问过
void Prim()//随机选取一个节点作为T
{
    memset(d,inf,sizeof(d));//初始距离为无穷
    memset(p,-1,sizeof(p));
    d[1] = 0;
    while(true)
    {
        int minconst = inf,u;//寻找T 与V - T之间的最短距离
        for(int i=1;i<=n;++i)
        {
            if(!vis[i]&&d[i]<minconst)
            {
                minconst = d[i];
                u = i;
            }
        }
        if(minconst == inf)
            break;//已经完成
        vis[u] = true;//访问u节点
        //更新d
        for(int v=1;v<=n;++v)
        {
            if(!vis[v]&&d[v]>Grape[u][v]&&Grape[u][v]!=-1)//如果节点未被访问且更新且存在边
            {
                d[v] = Grape[u][v];
                p[v] = u;
            }
        }
    }
}
int main()
{
	int m;
    cin>>m>>n;
    memset(Grape,inf,sizeof(Grape));
    for(int i=1;i<=m;++i)
    {
       int x,y,z;
       cin>>x>>y>>z;
       Grape[x][y]=Grape[y][x]=z;
    }//构建邻接图
    Prim();
    int sum = 0;
    for(int i=1;i<=n;++i)
    {
        if(p[i]!=-1)
            sum += Grape[i][p[i]];//(important学习了)
    }
    cout<<sum<<endl;
}
//求最小生成树的总路径
