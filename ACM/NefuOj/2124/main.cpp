//��ȡ������������һ����Χ��
#include<bits/stdc++.h>
using namespace std;
map<int,int>s;
int main() {
    int number,range,item,max_size=0;
    cin>>number>>range;
    //range��ʾ���ӵĳ��ȣ�����β�ͣ���number��ʾ��ʯ������
    while (number--){
        cin>>item;
        s[item]++;
        if (item>max_size)
            max_size=item;
        //��¼�����������ȷ������ͣ������λ��
    }
    int left=0,right=0,maxx=0;
    //������ӵ���ͺ�β�ͣ���������ʳ��������maxx
    number=0;//number�ϱ�������ʹ�ã������ӵĶ��ӣ���̬��
    for (;right<=range;right++){
        if (s[right]){
            number+=s[right];
        }
    }
    //���ó�����ֱ�����ó���right-left=range+1��right=range+1��number��������mapͰ�Ŵ�1Ϊ�±굽rangeΪ�±�����ĺ�
    maxx=number;
    for (;right<max_size;left++,right++){
        if (s[left]){
            number-=s[left];
        }
        if (s[right]){
            number+=s[right];
            if (number>maxx)
                maxx=number;
        }
    }
    //��ʼ�Ժ��£����Ҽ�¼���ֵ
    cout<<maxx;
    return 0;
}
