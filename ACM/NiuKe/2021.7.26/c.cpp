/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-26 14:06:03
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-26 15:03:44
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1010;
int a, b, c, n;
char s1[N], s2[N], s3[N];

int main()
{
    cin >> a >> b >> c >> n;
    int minn = min(a, b);
    minn = min(minn, c);
    if (a + b + c - 2 * minn > n){
        printf("NO");
        return 0;
    }
    for (int i = 0; i < minn; i++){
        s1[i] = 'a';
        s2[i] = 'a';
        s3[i] = 'a';
    }
    for (int i = minn; i < a; i++){
        s1[i] = 'b';
        s2[i] = 'b';
    }
    b -= minn;
    c -= minn;
    for (int i = a; i < a + b; i++){
        s2[i] = 'c';
        s3[i] = 'c';
    }
    for (int i = a + b; i < a + b + c; i++){
        s1[i] = 'd';
        s3[i] = 'd';
    }
    for (int i = 0; i < n; i++){
        if (s1[i]) cout << s1[i];
        else cout << 'x';
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        if (s2[i]) cout << s2[i];
        else cout << 'y';
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        if (s3[i]) cout << s3[i];
        else cout << 'z';
    }
    return 0;
}