#include <bits/stdc++.h>
using namespace std;
struct stu{
char name[256];
int num;
}a[1001];//直接在结构体下定义数组
bool judge (int t){
if(t%7==0)
    return 0;
while(t){
    if(t%10==7)
        return 0;
    t=t/10;}
    return 1;
}//bool型不用取地址
queue<stu>q;
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i].name;
        a[i].num=i;
    }//先把结构体的数据输入
    for(int i=1;i<=n;i++){
        q.push(a[i]);//将整个结构体数据输入队列中
    }//就是先输入全部的
    for(int i=1;i<=m-1;i++){
        q.push(a[i]);
        q.pop();
    }//再输入指定人的前几个人的，再删掉前面几个人的，就成了题目想要的顺序
    t--;
    while(q.size()>1){
        t++;
        stu tmp=q.front();//再定义一个tmp结构体储存队列的头，这个结构体包含name和num。
        q.pop();
        if(judge(t))//进行函数的判断
            q.push(tmp);
    }
    cout<<q.front().name;
    return 0;
}
