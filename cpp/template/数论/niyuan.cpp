//niyuan.cpp
/*
a m ����
ax === 1 mod m�൱��ax +my = 1
 ax+my = 1�Ĳ��裺
��1����x,y,t = gcd(a,m)
��2�����t != 1�޽�
��3������ax===1(mod m)��һ����Ϊx = x
*/
#include<iostream>
using namespace std;
//extend_gcd(a, m, &x, &y); xΪ����� when gcd(a,m) == 1
long mod_reverse(long long  a, long long  m){
	long long  y=0,x=1,r=a%m, q, t, mm=m;//��ʼ��
	if(r<0)r=r+m;
	while((m%r) != 0) {
		a=m; m=r;
		q= a/m; r=a % m;
		t=x; x=y-x*q; y=t;
	}
	if(r!=1) return 0;
	if(x<0) x=x+mm;
	return x;
}

int main(){
    long long a,m;
    while(cin>>a>>m){
        cout<<mod_reverse(a,m)<<endl;

    }
}
