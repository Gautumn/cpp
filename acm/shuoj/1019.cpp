
#include<bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define LOCAL
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
//const int MAXN = 10010;

//�ж�����
bool sushu(int x){
    for(int i = 2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}
int vis[10000];//�ж��Ƿ���������
int cnt[10000];//cnt[i]��¼��n��i�Ĳ���������������Ϊ����ؼ�
int main(){
    /*
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif */
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        memset(vis ,0 ,sizeof(vis));
        memset(cnt ,0 ,sizeof(cnt));
        queue<int> Q;
        Q.push(n);
        while(!Q.empty()){
            int temp = Q.front();Q.pop();
            vis[temp] = 1;
            if(temp == m)break;//���ҵ�temp == m�Ǽ����˳�ѭ��
            int i = 0;
            int  x = temp;
            int a[5];//��¼temp�ĸ���λ����С
            while(temp){
                a[i++] = temp%10;
                temp/=10;
            }
            REP(i,10){
                REP(j,4){
                    if(j==3&&i==0)continue;//ǧλΪ��ʱ����������
                    if(j==0) temp = i+a[1]*10+a[2]*100+a[3]*1000;//��λ��
                    if(j==1)temp = a[0]+i*10+a[2]*100+a[3]*1000;//ʮλ
                    if(j==2)temp = a[0]+a[1]*10+i*100+a[3]*1000;//��λ
                    if(j==3)temp = a[0]+a[1]*10+a[2]*100+i*1000;//ǧλ
                    if(vis[temp] == 0&&sushu(temp) == 1)
                        {
                            vis[temp] = 1;
                            cnt[temp] = cnt[x]+1;//��ǰһ�����䵽���ڵ�������������һ
                            Q.push(temp);
                    }
                }
            }
        }
        if(cnt[m]>0||n == m)
        cout<<cnt[m]<<endl;//�����n��m�Ĳ�������
        else cout<<"Impossible"<<endl;
    }

   //printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
