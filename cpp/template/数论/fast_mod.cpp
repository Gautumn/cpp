//fast_mod.cpp
/*
n^m(mod c)
A^13 = A^8*A^4*A^1�ö����Ʊ�ʾA^(1101) = A^(1000)*A^(100)*A^(1)
���磺��N = 13 = 1101��2����N>>1 = 110��2�� ��
*/
long long fast_mod(long long n,long long m,long long c){ //�������
    long long ret=1;
    while(m){
        if(m&1)ret = ret*n%c;
        n=n*n%c;//���ﱣ֤m����λ��n�������Եȣ�����xλ��Ϊn��2^x����
        m>>=1;
    }
    return ret;
}
