

#include<bits/stdc++.h>
using namespace std;


struct MY{
    int a,b;
    MY(){}
    MY(int a,int b):a(a),b(b){}
    bool operator<(const MY m)const{ //定义比较方式，这一步很重要
        return a<m.a;
    }
};

int main(){
    MY m[10];
    for(int i=0;i<10;i++){
        m[i] = MY(i+1,2*i);
        cout<<m[i].a<<"  "<<m[i].b<<endl;
    }
    cout<<"请输入你需要查找的数字a:"<<endl;
    int num;
    cin>>num;
    sort(m,m+10);//进行二分之前需要排序
    int aa =  lower_bound(m,m+10,MY(num,0)) - m;  //需要把我们查找的数封装成一个结构体才能进行查找。
    cout<<"查到位置为："<<aa<<endl;
    return 0;
}
