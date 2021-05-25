#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * @param s: The given string
     * @return: return the number of Five-character palindrome
     */
    int Fivecharacterpalindrome(string &s) {
        int cnt=0;
        for(register int i=0;i<s.size()-4;i++){
            string tmp=s.substr(i,5);
            string t=tmp;
            reverse(tmp.begin(),tmp.end());
            if(t==tmp){
                if(t[0]==t[4]&&t[1]==t[3]&&t[2]!=t[0]&&t[2]!=t[1]&&t[0]!=t[1]) cnt++;
            }
        }
        return cnt;
        /// abcbabcccb
    }
};
int main()
{
    Solution solution;
    string s;
    cin>>s;
    cout<<solution.Fivecharacterpalindrome(s)<<endl;
    return 0;
}
