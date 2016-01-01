//�й�ʣ�ඨ��.cpp
/*�� m1��m2,m3...mn���������ص�n����������
��m = m1m2m3...mn ��Mi = n/mi
��1��i��n����ô������ģ���Է�����
x === b1(mod m1)
x === b2(mod m2)
    ...
x === bn(mod mn)
�Ľ�Ϊx0 = (b1m1y1+b2m2y2+...+bnmnyn)��
����yi ��Miyi ===1(mod mi) �Ľ⣬i=1��2��3������n
*/
#include<iostream>
using namespace std;
const int maxn = 1000;
long long m[maxn];
long long b[maxn];
long long ChinaRemainder(int n,long long  m0[], long long  b[]){
	long long d,x,y,t,m=1,a=0,Mi;
	int  i;
	for (i=0; i< n ; i++)  m=m*m0[i];
	for (i=0; i< n ; i++) {
		Mi=m / m0[i];
		extend_gcd(Mi, m0[i], x, y); //����Ԫ��չŷ�����
        //��x=mod_reverse(MM, m0[i]);
		a=(a+Mi*x*b[i]) % m;
	}
	while(a<0)a = a+m;
	return a;
}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++)
            cin>>b[i]>>m[i];
        cout<<ChinaRemainder(n,m,b)<<endl;
    }
}
