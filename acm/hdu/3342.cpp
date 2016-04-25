
//��������
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
#define maxn 105
#define lowbit(X) (X & (-X))
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

/*

int t;
int c[maxn];
int Ans[maxn];
int G[maxn][maxn];
int n,m;

bool dfs(int v){
	c[v]=-1;//��ʾ���ڷ���
	for(int i=0;i<n;++i)if(G[v][i]){
		if(c[i]==-1)return false;
		if(c[i]==0 && !dfs(i))return false;
	}
	c[v]=1;//���ʽ���
	Ans[--t]=v+1;
	return 1;
}
bool toposort(int n){
	t=n;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;++i)if(!c[i]){
		if(!dfs(i))return false;
	}
	return true;
}
int main()
{
	while(cin>>n>>m&&n&&m){
        memset(G,0,sizeof(G));
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		//a--;b--;
		G[a][b]=1;
	}
	if(toposort(n)){
		cout<<"YES"<<endl;
	 	for(int i=0;i<n;++i){
		 	cout<<Ans[i]<<" ";
		 }
		 //cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	}


	return 0;
}*/
int n,m;
int deg[maxn];
int G[maxn][maxn];
int ans;
void toposort(int n) {//��������
    int k = 0;
    ans= 0;
    for (int i = 1; i <= n; i++) {//������|G.V|�β���
        for (int j = 1; j <= n; j++) {//�������еĶ���  �����Ϊ0��
            if (deg[j] == 0) {//�ҵ�
                ans++;
                //printf("%d%c", j, i == n ? '\n' : ' ');//���
                deg[j]--;//ȥ�������  ��deg[j] = -1;
                k = j;//��¼�����
                break;//����ѭ��
            }
        }
        for (int j = 1; j <= n; j++)//�������еĵ�
            if (G[k][j] == true) {//�ұ��˵��ܹ��ĵ�
                G[k][j] = false;//���Ϊ�ҵ���
                deg[j]--;//�����������-1
            }
    }
}

int main()
{
	while(cin>>n>>m&&n&&m){
        memset(G,0,sizeof(G));
        memset(deg,0,sizeof(deg));
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		a++;b++;
		if(G[a][b] == 0){//Ҫע�����أ��������
		deg[b]++;
		//a--;b--;
		G[a][b]=1;
		}
	}
	toposort(n);
	if(ans >= n){
		cout<<"YES"<<endl;
	 	/*for(int i=0;i<n;++i){
		 	cout<<Ans[i]<<" ";
		 }*/
		 //cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	}


	return 0;
}
