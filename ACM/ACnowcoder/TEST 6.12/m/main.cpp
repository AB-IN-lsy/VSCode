#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,string> m;
    m["q"] = "q";m["iu"] = "q";
    m["w"] = "w";m["ei"] = "w";
    m["e"] = "e";
    m["r"] = "r";m["uan"] = "r";
    m["t"] = "t";m["ue"] = "t";
    m["y"] = "y";m["un"] = "y";
    m["u"] = "u";m["sh"] = "u";
    m["i"] = "i";m["ch"] = "i";
    m["ch"] = "i";m["ch"] = "i";
    m["o"] = "o";m["uo"] = "o";
    m["p"] = "p";m["ie"] = "p";
    m["a"] = "a";
    m["s"] = "s";m["ong"] = "s";m["iong"] = "s";
    m["d"] = "d";m["ai"] = "d";
    m["f"] = "f";m["en"] = "f";
    m["g"] = "g";m["eng"] = "g";
    m["h"] = "h";m["ang"] = "h";
    m["j"] = "j";m["an"] = "j";
    m["k"] = "k";m["uai"] = "k";m["ing"] = "k";
    m["l"] = "l";m["uang"] = "l";m["iang"] = "l";
    m["z"] = "z";m["ou"] = "z";
    m["x"] = "x";m["ia"] = "x";m["ua"] = "x";
    m["c"] = "c";m["ao"] = "c";
    m["v"] = "v";m["zh"] = "v";m["ui"] = "v";
    m["b"] = "b";m["in"] = "b";
    m["n"] = "n";m["iao"] = "n";
    m["m"] = "m";m["ian"] = "m";
    string s;
    while(getline(cin, s)){
        string str = "", tmp = "";

        int cnt = 0;
        bool judge = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(judge == 0) cout << tmp[0];
                cout << m[tmp];
                tmp = "";
                str = "";
                cout << " ";
                cnt = 0;
                judge = 0;
                continue;
            }
            str += s[i];
            cnt += 1;
            if(m[str] == ""){
                if(tmp.size() == 1 || tmp.size() == 2) judge = 1;
                cout << m[tmp];
                tmp = ""; str= s[i];
            }
            tmp += s[i];
        }
        if(cnt == 1) cout << m[tmp];
        cout << m[tmp];
        cout << '\n';
    }
    return 0;
}
