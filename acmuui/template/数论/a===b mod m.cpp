//ax === b mod m.cpp
/*
ax === b(mod m)�൱��ax +my = b
����ǰ����  ax+my = b�Ĳ��裺
��1����x,y,t = gcd(a,m)
��2�����b%d!=0�޽�
��3�� ��ax+my = t,��a(x*b/t)+m(y*b/t) = b
    ����ax===b(mod m)��һ����Ϊx = x*b/t
 ��4��ax === b(mod m)�����н�Ϊ��
        x = (x*b/t+ i*m/t)mod m,i = 0,1,2,...d-1
*/
#include<iostream>
using namespace std;
int main(){
    long long  a,b,x,m,y;
    while(cin>>a>>b>>m){
        long long t = extend_gcd(a,m,x,y);//��չŷ�����
        if(b%t == 0){
            x =(x*b/t)%m;
        while(x<0)x = (x+m)%m;
            for(int i = 0;i<t;i++){
                cout<<(x+i*(m/t))%m<<endl;
                }
        }
        else cout<<"no solutions"<<endl;

    }
}
