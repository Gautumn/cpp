
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//�㷨�������ҿ��������ڽ��в���
//������е�Ԫ�ض���findС���򷵻�ֵԽ��
int main(){
    int a[] = {0,0,0,1,1,2,3,4,4,4,4,5,8};
    int n = 13;
    int l,r;
    int find;
    while(cin>>find){
        //ok_left,no_right
        l = 0;r = n;
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid]>=find) r = mid;
            else l = mid+1;
        }
        cout<<l<<endl;
        //no_left,ok_right
        l = 0;r = n;
        while(l<r){
            int mid = (l+r-1)/2+1;
            if(a[mid]<=find) l = mid;
            else r = mid-1;
        }
        cout<<l<<endl;
        //ok_left,no_right
        cout<<lower_bound(a,a+n,find) - a<<endl;
        //ok_right+1,no_right
        cout<<upper_bound(a,a+n,find) - a<<endl;
    }
}
