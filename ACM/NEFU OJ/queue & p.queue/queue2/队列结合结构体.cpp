#include <bits/stdc++.h>
using namespace std;
struct stu{
char name[256];
int num;
}a[1001];//ֱ���ڽṹ���¶�������
bool judge (int t){
if(t%7==0)
    return 0;
while(t){
    if(t%10==7)
        return 0;
    t=t/10;}
    return 1;
}//bool�Ͳ���ȡ��ַ
queue<stu>q;
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i].name;
        a[i].num=i;
    }//�Ȱѽṹ�����������
    for(int i=1;i<=n;i++){
        q.push(a[i]);//�������ṹ���������������
    }//����������ȫ����
    for(int i=1;i<=m-1;i++){
        q.push(a[i]);
        q.pop();
    }//������ָ���˵�ǰ�����˵ģ���ɾ��ǰ�漸���˵ģ��ͳ�����Ŀ��Ҫ��˳��
    t--;
    while(q.size()>1){
        t++;
        stu tmp=q.front();//�ٶ���һ��tmp�ṹ�崢����е�ͷ������ṹ�����name��num��
        q.pop();
        if(judge(t))//���к������ж�
            q.push(tmp);
    }
    cout<<q.front().name;
    return 0;
}
