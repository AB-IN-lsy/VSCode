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
    while(getline(cin, s))
    {
        string str="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=' ') str+=s[i];
            else
            {
                //cout<<str<<endl;
                if(str.size()==1) cout<<str<<str<<' ';
                else if(str.size()==2) cout<<str<<' ';
                else if(str=="uan") cout<<"ur ";
                else if(str=="ong") cout<<"os ";
                else if(str=="iong") cout<<"is ";
                else if(str=="eng") cout<<"eg ";
                else if(str=="ang") cout<<"ah ";
                else if(str=="uai") cout<<"uk ";
                else if(str=="ing") cout<<"ik ";
                else if(str=="uang") cout<<"ul ";
                else if(str=="iang") cout<<"il ";
                else if(str=="iao") cout<<"in ";
                else if(str=="ian") cout<<"im ";
                else
                {
                    if(str.substr(0,2)=="sh")
                    {
                        cout<<"u";
                        cout<<m[str.substr(2,str.size())];
                    }
                    else if(str.substr(0,2)=="ch")
                    {
                        cout<<"i";
                        cout<<m[str.substr(2,str.size())];
                    }
                    else if(str.substr(0,2)=="zh")
                    {
                        cout<<"v";
                        cout<<m[str.substr(2,str.size())];
                    }
                    else
                    {
                        cout<<str[0];
                        cout<<m[str.substr(1,str.size())];
                    }
                    cout<<" ";
                }
                str="";
            }

        }
        //cout<<str<<endl;
        if(str.size()==1) cout<<str<<str;
        else if(str.size()==2) cout<<str;
        else if(str=="uan") cout<<"ur";
        else if(str=="ong") cout<<"os";
        else if(str=="iong") cout<<"is";
        else if(str=="eng") cout<<"eg";
        else if(str=="ang") cout<<"ah";
        else if(str=="uai") cout<<"uk";
        else if(str=="ing") cout<<"ik";
        else if(str=="uang") cout<<"ul";
        else if(str=="iang") cout<<"il";
        else if(str=="iao") cout<<"in";
        else if(str=="ian") cout<<"im";
        else
        {
            if(str.substr(0,2)=="sh")
            {
                cout<<"u";
                cout<<m[str.substr(2,str.size())];
            }
            else if(str.substr(0,2)=="ch")
            {
                cout<<"i";
                cout<<m[str.substr(2,str.size())];
            }
            else if(str.substr(0,2)=="zh")
            {
                cout<<"v";
                cout<<m[str.substr(2,str.size())];
            }
            else
            {
                cout<<str[0];
                cout<<m[str.substr(1,str.size())];
            }
        }
        cout<<'\n';
    }
    return 0;
}
