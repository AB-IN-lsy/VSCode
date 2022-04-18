#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string str;
        getline(cin, str);
        cout << str << endl;                          //输出用户的原话
        str = regex_replace(str, regex("\\s+"), " "); //删除连续的多余空格
        str = regex_replace(str, regex(" ,"), ",");   //删除,前的空格
        str = regex_replace(str, regex(" \\."), "."); //删除.前的空格
        str = regex_replace(str, regex(" !"), "!");   //删除!前的空格
        str = regex_replace(str, regex(" \\?"), "?"); //删除?前的空格
        str = regex_replace(str, regex(" '"), "'");   //删除'前的空格
        if (str.front() == ' ')
            str.erase(str.begin()); //删除字符串行首的空格
        if (str.back() == ' ')
            str.pop_back(); //删除字符串行末的空格
        for (auto &it : str)
        {
            //把所有除I外的大写字母转小写
            if (isupper(it) && it != 'I')
            {
                it = tolower(it);
            }
        }
        str = regex_replace(str, regex("\\?"), "!");                    //替换所有的?为!
        str = regex_replace(str, regex("\\bcan you\\b"), "_I can");     //替换所有的can you为_I can
        str = regex_replace(str, regex("\\bcould you\\b"), "_I could"); //替换所有的could you为_I could
        str = regex_replace(str, regex("\\bI\\b"), "you");              //替换所有的独立的I为you
        str = regex_replace(str, regex("\\bme\\b"), "you");             //替换所有的独立的me为you
        str = regex_replace(str, regex("\\b_I\\b"), "I");               //为了避免重复替换而设置的_I换回I
        //必须先换can you/could you再换I和mem,不然有一个测试点一直卡3分
        cout << "AI: " << str << endl;
    }
    return 0;
}