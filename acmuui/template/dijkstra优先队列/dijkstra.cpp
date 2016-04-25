#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int>PII;
typedef vector<PII>VII;

const int MAXN = 100010;
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
