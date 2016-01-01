
#include<iostream>
#include<vector>
using namespace std;
/*��һ���������ߣ�u��v��ʱv�������ɫ��Ϊ���ߣ���ɫ������ߣ���ɫ��ǰ�������*/
/*��������û����һ���ڵ㣬�ӵ��C�У�ȫ�����꣬��ջ������������*/
/*ǿ��ͨ������1.ԭͼdfs��2.��ͼ��ת��3.����ԭͼ�ڵ����ʱ��Ľ���dfs��paΪ-1�ĸ���Ϊǿ�����ĸ���*/
vector<int >VZ[1000];//��¼ͼ
vector<int >VT[1000];
int id[1000];//idΪ��ɵ�ʱ��
int time_d[1000];//���ֽڵ��ʱ��
int time_f[1000];//��ɽڵ��ʱ��
int color[1000];// 0���ֵĽڵ� 1����δ��ɵĽڵ�2��ɵĽڵ�
int pa[1000];//���׽ڵ�
void dfs_visit(vector<int> *V,int v,int &time){
	time++;
	time_d[v] = time;
	color[v] = 1;
	int _size =  V[v].size();
	for(int i = 0;i<_size;i++)
		if(color[V[v][i]] == 0){
			pa[V[v][i]] = v;
			dfs_visit(V,V[v][i],time);
		}
	color[v] = 2;
	time++;
	time_f[v] = time;
}
void dfs(vector<int> *V,int m,int n){
	//��ʼ��
	for(int i = 1;i<=m;i++){
		color[i] = 0;pa[i] = -1;
	}
	//��ÿ���ڵ�����
	int time = 0;
	for(int i = 1;i<=m;i++){
		if(color[i] == 0){
			dfs_visit(V,i,time);
		}
	}
}
void dfsT(vector<int> *V,int m,int n){
	//��ʼ��
	for(int i = 1;i<=m;i++){
		color[i] = 0;pa[i] = -1;
	}
	//��ÿ���ڵ�����
	int time = 0;
	for(int i = 1;i<=m;i++){
		if(color[id[i]] == 0&&id[i]!= 0){
			dfs_visit(V,id[i],time);
		}
	}
}
int main(){
    int m,n;
    while(cin>>m>>n){
    //��ͼ
        for(int i = 0;i<n;i++){
            int a,b;
            cin>>a>>b;
            id[i] = 0;
            VZ[a].push_back(b);
            VT[b].push_back(a);
        }
        //�����������������
        dfs(VZ,m,n);
        for(int i = 1;i<=m;i++){
            cout<<i<<" "<<time_f[i]<<endl;
        }cout<<endl;
         for(int i = 1;i<=m;i++)
            id[time_f[i]] = i;
        dfsT(VT,m,n);
        int ans = 0;
        for(int i = 1;i<=m;i++){
            cout<<i<<" "<<time_f[i]<<endl;
            if(pa[i] == -1)ans++;
        }
        cout<<ans;

    }
}
/*
8 14
3 4
3 7
7 6
7 8
6 7
8 8
4 3
4 8
2 3
2 5
2 6
5 1
5 6
1 2



*/
