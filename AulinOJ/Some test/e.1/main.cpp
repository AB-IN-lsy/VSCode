#include<bits/stdc++.h>
using namespace std;
int getMinSwaps(vector<int> &nums){
    //����
    vector<int> nums1(nums);
    sort(nums1.begin(),nums1.end());
    map<int,int> m;
    int len = nums.size();
    for (int i = 0; i < len; i++){
        m[nums1[i]] = i;//����ÿ��Ԫ������Ӧ��λ�õ�ӳ���ϵ
    }
    int loops = 0;//ѭ���ڸ���
    vector<bool> flag(len,false);
    //�ҳ�ѭ���ڵĸ���
    for (int i = 0; i < len; i++){
        if (!flag[i]){//�Ѿ����ʹ���λ�ò��ٷ���
            int j = i;
            while (!flag[j]){
                flag[j] = true;
                j = m[nums[j]];//ԭ������jλ�õ�Ԫ�������������е�λ��
            }
            loops++;
        }
    }
    return len - loops;
}
int n,x;
int main()
{
    vector<int>vis;
    cin>>n;
    while(n--){
        cin>>x;
        vis.push_back(x);
    }
    int ans=getMinSwaps(vis);
    cout<<ans;
    return 0;
}
