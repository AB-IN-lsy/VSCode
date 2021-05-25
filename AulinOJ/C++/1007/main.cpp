#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int x1=x,x2=y;
    for(int i=1;i<=n;i++)
    {
        printf("(%d,%d)",x,i);
    }
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        printf("(%d,%d)",i,y);
    }
    printf("\n");
    while(x>=1&&y>=1){
        x--;
        y--;
    }
    x++;y++;
    while(x<=n&&y<=n){
        printf("(%d,%d)",x,y);
        x++;y++;
    }
    printf("\n");
    x=x1;y=x2;
    while(x<=n&&y>=1){
        x++;y--;
    }
    x--;y++;
    while(x<=n&&y<=n&&x>0&&y>0){
        printf("(%d,%d)",x,y);
        x--;y++;
    }
    printf("\n");
    return 0;
}
