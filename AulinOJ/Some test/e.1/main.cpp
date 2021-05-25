#include<bits/stdc++.h>
using namespace std;
int getMinSwaps(vector<int> &nums){
    //排序
    vector<int> nums1(nums);
    sort(nums1.begin(),nums1.end());
    map<int,int> m;
    int len = nums.size();
    for (int i = 0; i < len; i++){
        m[nums1[i]] = i;//建立每个元素与其应放位置的映射关系
    }
    int loops = 0;//循环节个数
    vector<bool> flag(len,false);
    //找出循环节的个数
    for (int i = 0; i < len; i++){
        if (!flag[i]){//已经访问过的位置不再访问
            int j = i;
            while (!flag[j]){
                flag[j] = true;
                j = m[nums[j]];//原序列中j位置的元素在有序序列中的位置
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
