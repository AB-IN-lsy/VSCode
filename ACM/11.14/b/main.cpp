

#include<bits/stdc++.h>
using namespace std;


struct MY{
    int a,b;
    MY(){}
    MY(int a,int b):a(a),b(b){}
    bool operator<(const MY m)const{ //����ȽϷ�ʽ����һ������Ҫ
        return a<m.a;
    }
};

int main(){
    MY m[10];
    for(int i=0;i<10;i++){
        m[i] = MY(i+1,2*i);
        cout<<m[i].a<<"  "<<m[i].b<<endl;
    }
    cout<<"����������Ҫ���ҵ�����a:"<<endl;
    int num;
    cin>>num;
    sort(m,m+10);//���ж���֮ǰ��Ҫ����
    int aa =  lower_bound(m,m+10,MY(num,0)) - m;  //��Ҫ�����ǲ��ҵ�����װ��һ���ṹ����ܽ��в��ҡ�
    cout<<"�鵽λ��Ϊ��"<<aa<<endl;
    return 0;
}
