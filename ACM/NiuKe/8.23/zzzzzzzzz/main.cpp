#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param inputQueries: input Queries, means [[m1, d1, m2, d2, x], [m1, d1, m2, d2, x],...]
     * @return: guess whether y1 is leep year
     */
    int r[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int p[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int run_ping(int m1,int d1,int m2,int d2,int x)
    {
            int flag1=0;
            if(x<=r[m1]-d1)
            {
                if(d1+x==d2) flag1=1;
            }
            else
            {
                int tmp=x-(r[m1]-d1);
                m1++;
                if(m1==13){
                    m1=1;
                    goto label;
                }
                while(tmp>r[m1]){
                    tmp-=r[m1];
                    m1++;
                    if(m1==13)
                    {
                        m1=1;
                        break;
                    }
                }
                if(m1==13) m1=1;
                label:
                while(tmp>p[m1]){
                    tmp-=p[m1];
                    m1++;
                }
                if(m1==13) m1=1;
                if(tmp==d2) flag1=1;
            }
            return flag1;
    }
    int ping_ping(int m1,int d1,int m2,int d2,int x)
    {
            int flag2=0;
            if(x<=p[m1]-d1)
            {
                if(d1+x==d2) flag2=1;
            }
            else
            {
                int tmp=x-(p[m1]-d1);
                m1++;
                if(m1==13) m1=1;
                while(tmp>p[m1]){
                    tmp-=p[m1];
                    m1++;
                    if(m1==13) m1=1;
                }
                if(tmp==d2) flag2=1;
            }
            return flag2;
    }
    int ping_run(int m1,int d1,int m2,int d2,int x)
    {
            int flag2=0;
            if(x<=p[m1]-d1)
            {
                if(d1+x==d2) flag2=1;
            }
            else
            {
                int tmp=x-(p[m1]-d1);
                m1++;
                if(m1==13){
                    m1=1;
                    goto label;
                }
                while(tmp>p[m1]){
                    tmp-=p[m1];
                    m1++;
                    if(m1==13){
                        m1=1;
                        break;
                    }
                }
                if(m1==13) m1=1;
                label:
                while(tmp>r[m1]){
                    tmp-=r[m1];
                    m1++;
                }
                if(tmp==d2) flag2=1;
            }
            return flag2;
    }
    string guessYear(vector<vector<int>> &inputQueries) {
        // write your code here
        string s;
        for(auto i:inputQueries){
            int m1=i[0],d1=i[1],m2=i[2],d2=i[3],x=i[4],flag1=0,flag2=0;
            if(m1==2 && d1==29)
            {
                flag1=1;
            }
            else if(m2==2 && d2==29 && m1>m2)
            {
                flag2=1;
            }
            else if(m2==2 && d2==29)
            {
                flag1=1;
            }
            else{
                flag1=run_ping(m1,d1,m2,d2,x);
                flag2=max(ping_run(m1,d1,m2,d2,x),ping_ping(m1,d1,m2,d2,x));
            }
            if(flag1 && flag2) s+="?";
            else if(flag1) s+="R";
            else if(flag2) s+="P";
            else s+="?";
        }
        return s;
    }
};
//[[2,28,3,2,2],[2,28,3,1,2],[12,31,1,1,1],[2,16,1,23,341],[2,29,1,2,308],[12,31,12,31,0],[7,31,9,2,33],[7,31,8,31,31],[2,29,12,31,306],[6,3,2,29,271],[6,3,1,10,221],[2,28,2,29,1],[1,1,2,28,58],[1,1,2,29,59],[2,1,2,29,28],[1,1,8,31,243],[1,1,8,31,242],[6,1,3,1,273],[6,1,3,1,274],[3,1,6,1,92],[12,31,1,1,1],[7,31,3,1,213],[7,31,3,1,214],[2,1,2,28,27],[2,15,3,1,15],[2,15,3,1,14]]
int main()
{
    Solution solution;
    vector < vector<int> > a(1);
    a[0]={12,31,3,1,61};
    /*a[1]={6,1,3,1,273};
    a[2]={6,1,3,1,274};*/
    cout<<solution.guessYear(a);
}
