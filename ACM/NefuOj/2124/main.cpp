//尺取法（区间内数一个范围）
#include<bits/stdc++.h>
using namespace std;
map<int,int>s;
int main() {
    int number,range,item,max_size=0;
    cin>>number>>range;
    //range表示虫子的长度（不加尾巴），number表示钻石的总数
    while (number--){
        cin>>item;
        s[item]++;
        if (item>max_size)
            max_size=item;
        //记录最大数量，以确定虫子停下来的位置
    }
    int left=0,right=0,maxx=0;
    //定义虫子的嘴巴和尾巴，还有所吃食物的最大量maxx
    number=0;//number废变量重新使用，当虫子的肚子（动态）
    for (;right<=range;right++){
        if (s[right]){
            number+=s[right];
        }
    }
    //先让虫子伸直，即让虫子right-left=range+1，right=range+1，number容下了用map桶排从1为下标到range为下标的数的和
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
    //开始吃和吐，并且记录最大值
    cout<<maxx;
    return 0;
}
