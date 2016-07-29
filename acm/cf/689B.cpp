#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define lson l,m,rt<<1
#define rson m+1,r,tr<<1|1
typedef pair<int,int>PII;
typedef vector<PII>VII;
const int MAXN = 200110;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}

vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
//��������һ�汾һ��
int vis[MAXN];
int dis[MAXN];
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII,VII,greater<PII> >q;//�������ȶ��У�ÿ�δӶ�����ȡ�����Ǿ����������Ȩ��Ԫ�ء�
    //���ȶ��е�һ������Ϊ�Ƚ����ͣ��ڶ���Ϊ�������ͣ�������Ϊ�ȽϺ�����
	//greaterʵ��С����//less ʵ�ִ󶥶ѣ�Ĭ��Ϊ�󶥶ѣ�
	q.push(MP(dis[s],s));//�����������ƽ����ȶ���
    while(!q.empty()){//�����п�ʱ�ѽ����б߼�����в��Ƴ�
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<G[x].size();i++){//ÿһ����x���ڵı߶�Ҫ����
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                q.push(MP(dis[y],y));//��ÿһ�����µĳ��ȼӽ�����
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        init(n+1);
        for(int i = 1;i<n;i++){
            add_edge(i,i,0);
            add_edge(i,i+1,1);
            add_edge(i+1,i,1);
        }
        add_edge(n,n,0);
        for(int i = 1;i<=n;i++){
            int t;
            cin>>t;
            if(t != i)
            add_edge(i,t,1);
        }
        dijkstra(1,n+1);
        for(int i = 1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;
    }
}

