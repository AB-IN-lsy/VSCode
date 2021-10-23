#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '6'){
            int cnt = 0, index;
            for(int j = i; j < s.size(); j++){
                if(s[j] == '6') cnt ++;
                else {
                    index = j - 1;
                    break;
                }
            }
            if(cnt > 3 && cnt < 9) {
                s.replace(i, index - i + 1, "9");
            }
            if(cnt >= 9) {
                s.replace(i, index - i + 1, "27");
            }
        }
    }
    cout << s << endl;
    return 0;
}
