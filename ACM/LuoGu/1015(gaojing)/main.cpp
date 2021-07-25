#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
char six[20]="0123456789ABCDEF";
bool huiwen(string str1)
{
    string str2=str1;
    reverse(str1.begin(),str1.end());
    return str1==str2;
}
string gaojingjia(int k,string str1)
{
    ///此时为k进制 两个相同位数的数做加法
    ///tip1:若是10进制，则把k改成10即可
    ///tip2:若两个位数不同
    /*
    int len1=str1.length();
    int len2=str2.length();
    //前面补0，弄成长度相同
    if(len1<len2){
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else{
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    */
    int num1[maxn]={0},num2[maxn]={0},sum[maxn]={0};
    int len=str1.length(),len_sum=1,x=0;
    string str2=str1;
    reverse(str1.begin(),str1.end());
    for(int i=0;i<len;i++){
        if(isdigit(str1[i]))
            num1[len-i]=str1[i]-'0';
        else
            num1[len-i]=str1[i]-'A'+10;
        if(isdigit(str2[i]))
            num2[len-i]=str2[i]-'0';
        else
            num2[len-i]=str2[i]-'A'+10;
    }
    while(len>=len_sum){
        sum[len_sum]=num1[len_sum]+num2[len_sum]+x;
        x=sum[len_sum]/k;
        sum[len_sum]%=k;
        len_sum++;
    }
    sum[len_sum]=x;
    while(sum[len_sum]==0)
        len_sum--;
    string str;
    for(int i=len_sum;i>=1;i--)
        str+=six[sum[i]];
    return str;
}
int n;string m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<=30;i++){
        if(huiwen(m)){
            printf("STEP=%d\n",i);
            return 0;
        }
        else
            m=gaojingjia(n,m);
    }
    printf("Impossible!");
    return 0;
}
