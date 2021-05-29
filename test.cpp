/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-28 22:52:17
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

typedef long long int ll;
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    multiset<char> a;
    for (int i = 0; i < n; ++i) {
        auto tmp = a.upper_bound(str[i]);
        if (tmp != a.end()) a.erase(tmp);
        a.insert(str[i]);
    }
    cout << n-a.size();
    return 0;
}