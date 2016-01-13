#include<bits/stdc++.h>
using namespace std;


//求网络最小费用最大流,邻接阵形式
//返回最大流量,flow返回每条边的流量,netcost返回总费用
//传入网络节点数n,容量mat,单位费用cost,源点source,汇点sink
#define MAXN 20
#define inf 1000000000
int mat[MAXN][MAXN];
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];

int min_cost_max_flow(int n,int mat[][MAXN],int cost[][MAXN],int source,int sink,int flow[][MAXN],int& netcost){
	int pre[MAXN],min[MAXN],d[MAXN],i,j,t,tag;
	if (source==sink)
		return inf;
	for (i=0;i<n;i++)
	for (j=0;j<n;flow[i][j++]=0);
	for (netcost=0;;){
		for (i=0;i<n;i++)
			pre[i]=0,min[i]=inf;
		//通过bellman_ford寻找最短路，即最小费用可改进路
		for (pre[source]=source+1,min[source]=0,d[source]=inf,tag=1;tag;)
		for (tag=t=0;t<n;t++)
			if (d[t])
				for (i=0;i<n;i++)
					if (j=mat[t][i]-flow[t][i]&&min[t]+cost[t][i]<min[i])
						tag=1,min[i]=min[t]+cost[t][i],pre[i]=t+1,d[i]=d[t]<j?d[t]:j;
					else if (j=flow[i][t]&&min[t]<inf&&min[t]-cost[i][t]<min[i])
						tag=1,min[i]=min[t]-cost[i][t],pre[i]=-t-1,d[i]=d[t]<j?d[t]:j;
		if (!pre[sink])	break;
		for (netcost+=min[sink]*d[i=sink];i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}

	for (j=i=0;i<n;j+=flow[source][i++]);
	return j;
}

int main(){
	int T;
	cin>>T;
	for (int t = 1;t<=T;t++){
		int n,m;
		cin>>n>>m;
		int a,b,c;
		memset(mat,0,sizeof(mat));
		memset(cost,0,sizeof(cost));
		for(int i = 0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			mat[a][b] = c;
		}
		int netcost = 0;
		cout<<"Case "<<t<<": "<<min_cost_max_flow(n,mat,cost,0,n-1,flow,netcost);
		//cout<<netcost<<endl;
		//cout<<"reate<<endl"<<endl;
	}
}
