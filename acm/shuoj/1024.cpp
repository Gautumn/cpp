#include <stdio.h>
int main() //��main���������int����
{
int a,b;
while(scanf("%d %d",&a, &b) != EOF) // �������ʱ��scanf��������ֵΪEOF����û����������ʱ���˳�whileѭ��
printf("%d\n",a+b);
return 0; //����ֵΪ0
}

/**************************************************************
    Problem: 1024
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
