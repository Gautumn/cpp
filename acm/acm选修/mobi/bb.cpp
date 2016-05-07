#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long 
#define maxn 70

LL prime[maxn];
LL make_ans(LL num,int m)
{
	LL ans=0,tmp,i,j,flag;
	for(i=1;i<(LL)(1<<m);i++) //�ö�������1,0����ʾ�ڼ����������Ƿ��õ�,��m=3������������2,3,5����i=3ʱ��������011����ʾ��2��3�����ӱ��õ� 
	{
		tmp=1,flag=0;
		for(j=0;j<m;j++) 
			if(i&((LL)(1<<j)))//�жϵڼ�������Ŀǰ���õ�
				flag++,tmp*=prime[j];
		if(flag&1)//�ݳ�ԭ�����ż�� 
			ans+=num/tmp;
		else
			ans-=num/tmp;
	}
	return ans;
}

int main()
{
	int T,t=0,m;
	LL n,a,b,i;
	while(~scanf("%I64d%I64d",&b,&n))
	{
		a = 1;
		m=0;
		for(i=2;i*i<=n;i++) //��n���������ӷֽ� 
			if(n&&n%i==0)
			{
				prime[m++]=i;
				while(n&&n%i==0)
					n/=i;
			}	
		if(n>1)
			prime[m++]=n;
		printf("%I64d\n",(b-make_ans(b,m))-(a-1-make_ans(a-1,m)));
	}
	return 0;
}
