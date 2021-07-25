#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
#include<queue>
#include<deque>
#include<map>
#include<set>
using namespace std;

const int N=10;
int a[N][N];


struct sa
{
    int x;
    int y;
    int num;
    int step;
};
set < int > s;
queue< sa >q;

int x2[]={1,0,0,-1};
int y2[]={0,1,-1,0};

void bfs(int x , int y , int num)
{
    q.push( (sa) {x,y,num,0});
    while(!q.empty()){
        sa tmp=q.front();
        q.pop();
        int xx=tmp.x;
        int yy=tmp.y;
        int num=tmp.num;
        int step=tmp.step;
        if(step == 5){
            if(s.find(num) == s.end()){
                s.insert(num);
            }
            continue;
        }
        for(int i = 0 ;i < 4; i++){
            int x3=xx+x2[i];
            int y3=yy+y2[i];
            if( x3 >= 1 && x3 <= 5 && y3 >= 1 && y3 <= 5)
                q.push( (sa) {x3,y3,a[x3][y3]+num*10,step+1});
        }
    }
}

int main()
{
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            bfs(i,j,a[i][j]);
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
