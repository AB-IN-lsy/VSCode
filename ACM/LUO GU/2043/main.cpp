#include<iostream>
using namespace std;
int a[10001]={0},n; //����ܴ󣬼ǵÿ�������Ŷ
int main()
{
    cin>>n;
    for (int i=2;i<=n;i++) //1�Ͳ����ˣ���2��nһ��һ����
    {
        int i2=i;  //����һ�£���Ȼ�Ȼᱻ������
        for (int j=2;j<=i;j++)  //��2��ʼ�ж��Ƿ��������
            while (i2%j==0)
                {
                    a[j]++;
                    i2/=j;
                }
            //�ǵ�ʹ��while������if��Ҫһ������
    }
    for (int i=1;i<=10000;i++)  //���
        if (a[i]!=0)
            cout<<i<<" "<<a[i]<<endl;
}
