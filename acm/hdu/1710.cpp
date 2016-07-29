#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int  pre_arr[maxn];
int  in_arr[maxn];
int  la_arr[maxn];
//���������
int cnt = 0;
typedef struct BiTNode{
int data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;





void CreateBinaryTreeHelp(BiTree &r, int pre[], int in[],
							int preLeft, int preRight, int inLeft, int inRight)
// �����������֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]����
//	��rΪ���Ķ�����
{
	if (inLeft > inRight)
	{	// �������޽��,�ն�����
		r = NULL;			// �ն�������Ϊ��
	}
	else
	{	// �������н��,�ǿն�����
//		r = new BiTNode(pre[preLeft]);// ���ɸ����
		r = (BiTree)malloc(sizeof(BiTNode));
		r->data = pre[preLeft];
		int mid = inLeft;
		while (in[mid] != pre[preLeft])
		{	// ����pre[preLeft]��in[]�е�λ��,Ҳ�������������и���λ��
			mid++;
		}
		CreateBinaryTreeHelp(r->lchild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// ����������
		CreateBinaryTreeHelp(r->rchild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,
			inRight);								// ����������
	}
}
void CreateBiTree(BiTree &T,int pre[], int in[], int n)
// �����������֪������������й��������
{
							// �������ĸ�
	CreateBinaryTreeHelp(T, pre, in, 0, n - 1, 0, n - 1);
		// ��������������й�����rΪ���Ķ�����
	return ;				// ������rΪ���Ķ�����
}

void Visit(BiTree T){
    la_arr[cnt++] = T->data;
//    if(T->data != '#'){
//        printf("%d %d\n",T->data,cnt-1);
//    }
}
int LaOrder(BiTree T){
    if(T != NULL){
        //�������ӽ��
        LaOrder(T->lchild);
        //�������ӽ��
        LaOrder(T->rchild);
        //���ʸ��ڵ�
        Visit(T);
    }}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++)cin>>pre_arr[i];
        for(int i = 0;i<n;i++)cin>>in_arr[i];
        BiTree T;

        CreateBiTree(T,pre_arr,in_arr,n);
        cnt = 0;
        LaOrder(T);

        for(int i = 0;i<n;i++)i != (n-1)?cout<<la_arr[i]<<" ":cout<<la_arr[i]<<endl;

    }
}
