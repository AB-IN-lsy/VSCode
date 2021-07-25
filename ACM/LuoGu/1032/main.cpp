#include <bits/stdc++.h>

using namespace std;
struct sa{
    string s;
    int step;
};
queue<sa> q;
string a,b,a1,b1,a2[8],b2[8];
unordered_map<string,int>m;
int n=1;
int main()
{
	cin>>a>>b;
    while(cin>>a2[n]>>b2[n]) n++;
    n--;
    q.push( (sa) {a,0});
    while(!q.empty())
    {
        sa tmp=q.front();
        string s=tmp.s;
        if(m[s]){
            q.pop();
            continue;
        }
        q.pop();
        int step=tmp.step;
        if(s==b && step<=10){
            cout<<step<<endl;
            return 0;
        }
        if(step>10){
            cout<<"NO ANSWER!"<<endl;
            return 0;
        }
        m[s]=1;
        for(int i=1;i<=n;i++){
            a1=a2[i];
            b1=b2[i];
            if(s.find(a1)==-1) continue;
            for(int j=s.find(a1);j<s.length()&&j!=-1 ;j=s.find(a1,j+1)){
                string s1=s;
                //s1.erase(s1.begin()+j,s1.begin()+j+a1.size());
                //s1.insert(j,b1);
                s1.replace(j,a1.size(),b1);
                q.push( (sa) {s1,step+1});
            }
        }
    }
    cout<<"NO ANSWER!"<<endl;
	return 0;
}
