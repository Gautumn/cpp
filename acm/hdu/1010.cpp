
#include <bits/stdc++.h>
using namespace std;
char ma[9][9];        //��ͼ��಻����7��7��,�ִ�(1,1)����,���Կ���9,9
int n,m,t,di,dj;       //������������,�Լ��յ�λ��
bool escape;           //��ʶ�����ɹ�
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};  //�ֱ��ʾ���ҡ��¡����ĸ�����
void DFS(int si,int sj,int cnt)
{
    int i,temp;
    if (si>n || sj>m || si<=0 || sj<=0)   //Խ���߽�㲻����
        return;
    if (si==di && sj==dj && cnt==t)
    {
        escape=1;                   //ʱ�����õ�ʱ���������
        return;
    }
    temp=abs(t-cnt)-(abs(di-si)+abs(dj-sj));     //���㵱ǰ���յ�����·�뻹��Ҫ��ʱ���,��С��0��·����֦
    if (temp<0 || temp&1)           //temp����������Ļ�ҲҪ��֦
        return;
    for (i=0;i<4;i++)
    {
        if (ma[si+dir[i][0]][sj+dir[i][1]]!='X')
        {
            ma[si+dir[i][0]][sj+dir[i][1]]='X';  //�ѵ�ǰ��ˢΪX
            DFS(si+dir[i][0],sj+dir[i][1],cnt+1); //�����õ�
            if (escape)
                return;
            ma[si+dir[i][0]][sj+dir[i][1]]='.';  //������������˳�����,�����°Ѹõ�ˢΪ'.'
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,si,sj,wall;
    while (cin>>n>>m>>t)
    {
        if (n==0 && m==0 && t==0)
        {
            break;
        }
        wall=0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                cin>>ma[i][j];
                if (ma[i][j]=='S')
                {
                    si=i,sj=j;
                }
                else if (ma[i][j]=='D')
                {
                    di=i,dj=j;
                }
                else if (ma[i][j]=='X')
                {
                    wall++;
                }
            }
        }
        if (n*m-wall<=t)      //·����֦,�����겻��ǽ���Թ���������Tʱ�佫��������
        {
            cout<<"NO"<<endl;
            continue;
        }
        escape=0;
        ma[si][sj]='X';      //�ǵ�ˢΪ'X'
        DFS(si,sj,0);
        if (escape)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}





