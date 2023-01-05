/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-05 16:08:20
 * @FilePath: \GPLT\A1022\A1022.cpp
 * @LastEditTime: 2023-01-05 20:09:54
 */
#include <bits/stdc++.h>

using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)

const int N = 1e4 + 10;
int n, m;
struct sa
{
    string id;
    string title;
    string name;
    set<string> words;
    string pub;
    string year;
};

int main()
{
    cin >> n;
    getchar();
    vector<sa> a(n);
    for (int i = 0; i < n; ++i)
    {
        getline(cin, a[i].id);
        getline(cin, a[i].title);
        getline(cin, a[i].name);

        string words, word;
        getline(cin, words);
        istringstream ssin(words);
        while (ssin >> word)
            a[i].words.insert(word);

        getline(cin, a[i].pub);
        getline(cin, a[i].year);
    }

    cin >> m;
    getchar();

    int op;
    string q;
    while (m--)
    {
        vector<string> ans;
        getline(cin, q);
        cout << q << '\n';
        op = q[0] - '0';
        string ques = q.substr(3);

        for (auto &[id, title, name, words, pub, year] : a)
        {
            switch (op)
            {
            case 1:
                if (title == ques)
                    ans.push_back(id);
                break;
            case 2:
                if (name == ques)
                    ans.push_back(id);
                break;
            case 3:
                if (words.count(ques))
                    ans.push_back(id);
                break;
            case 4:
                if (pub == ques)
                    ans.push_back(id);
                break;
            case 5:
                if (year == ques)
                    ans.push_back(id);
                break;
            default:
                break;
            }
        }
        if (!SZ(ans))
        {
            cout << "Not Found\n";
            continue;
        }
        sort(ans.begin(), ans.end());
        for (auto id : ans)
            cout << id << '\n';
    }

    return 0;
}