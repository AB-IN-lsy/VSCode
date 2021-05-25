#include<iostream>
using namespace std;
int a[10001]={0},n; //数组很大，记得开在外面哦
int main()
{
    cin>>n;
    for (int i=2;i<=n;i++) //1就不用了，从2到n一个一个来
    {
        int i2=i;  //备份一下，不然等会被除掉了
        for (int j=2;j<=i;j++)  //从2开始判断是否可以整除
            while (i2%j==0)
                {
                    a[j]++;
                    i2/=j;
                }
            //记得使用while，不是if，要一除到底
    }
    for (int i=1;i<=10000;i++)  //输出
        if (a[i]!=0)
            cout<<i<<" "<<a[i]<<endl;
}
