#include <stdio.h>
int main() //��main���������int����
{
int a,b,t;
scanf("%d",&t);
while(t--) // �������ʱ��scanf��������ֵΪEOF����û����������ʱ���˳�whileѭ��

{
scanf("%d%d",&a,&b);
printf("%d\n",a+b);

}
return 0; //����ֵΪ0
}

/**************************************************************
    Problem: 1025
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
