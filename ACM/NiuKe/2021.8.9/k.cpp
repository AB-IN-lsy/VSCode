/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-09 16:20:42
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-09 16:20:42
 */

#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
int t;
double w,d;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf",&w,&d);
        double minx=min(w,d);
        double bei=PI/minx;
        //cout<<bei<<endl;
        double hh=sqrt(w*w+d*d);
        double bei1=PI/hh;
        printf("%d\n",max((int)floor(bei)*2+4,(int)floor(bei1)*3+4));
    }
    return 0;
}