
//拓扑排序
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
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define M_PI 3.14159265358979323846
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define X first
#define Y second
#define MAX_V 10101
#define maxn 10005
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

int n,m;
int deg[maxn];//入度
int ans;//已经出来的边数
int Ans[maxn];//记录的深度
int Cnt[maxn];//记录每次出来的信息

vector<int> G[maxn];
void add_edge(int u,int v){
    G[u].PB(v);
	deg[v]++;
}
void init(int n){
	memset(deg,0,sizeof(deg));
	memset(Ans,0,sizeof(Ans));
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
}

void toposort(int n) {//拓扑排序
	queue<int> Q;
    ans= 0;
	int cnti = 0;
	int cntj = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		 if (deg[i] == 0) {//找到
			Q.push(i);
			cnti = i;
		 }
	}
	while(!Q.empty()){
		int top = Q.front();Q.pop();
		ans++;
		Ans[cnt]++;
		deg[top]--;
		for (int j = 0; j < G[top].size(); j++){//遍历所有的点
            deg[G[top][j]]--;//让这个点的入度-1
            if(deg[G[top][j]] == 0){
                Q.push(G[top][j]);
                cntj = G[top][j];
            }
		}
		if(top == cnti){cnti = cntj;cnt++;}
	}

}

int main()
{
	while(cin>>n>>m){
        init(n);
        for(int i=1;i<=m;++i){
            int a,b;
            cin>>a>>b;
            //a++;b++;
            add_edge(b,a);
        }
        toposort(n);
        int sum = 888*n;
        if(ans >= n){
            //cout<<"YES"<<endl;
            for(int i=0;i<n;++i){
                sum += Ans[i]*i;
             }
             cout<<sum<<endl;
        }else{
            cout<<"-1"<<endl;
        }
	}
	return 0;
}



