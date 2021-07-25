#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<sin(180)<<endl;
    int t;
    double xans,yans,zans;
    while(t--){
        int a,b,c,x,y,z,r;
        cin>>a>>b>>c>>x>>y>>z>>r;
        int hh=a*x+b*y+c*z;
        double x1=1.0*hh*a/(a+b+c);
        double y1=1.0*hh*b/(a+b+c);
        double z1=1.0*hh*c/(a+b+c);
        double ju=sqrt(pow(x1-x,2)+pow(y1-y,2)+pow(z1-z,2));
        double ju1=ju*cos(r*3.14/180);
        double x2=x1+(x-x1)*ju1/ju;
        double y2=y1+(y-y1)*ju1/ju;
        double z2=z1+(z-z1)*ju1/ju;
        double xx=b*(z-z1)-c*(y-y1);
        double yy=c*(x-x1)-a*(z-z1);
        double zz=a*(y-y1)-b*(x-x1);
        if(zz>0){
            xans=x2-xx/sqrt(xx*xx+yy*yy+zz*zz)*ju*sin(r*3.14/180);
            yans=y2-yy/sqrt(xx*xx+yy*yy+zz*zz)*ju*sin(r*3.14/180);
            zans=z2-zz/sqrt(xx*xx+yy*yy+zz*zz)*ju*sin(r*3.14/180);
        }
        else{
            xans=x2+xx/sqrt(xx*xx+yy*yy+zz*zz)*ju*sin(r*3.14/180);
            yans=y2+yy/sqrt(xx*xx+yy*yy+zz*zz)*ju*sin(r*3.14/180);
            zans=z2+zz/sqrt(xx*xx+yy*yy+zz*zz)*ju*sin(r*3.14/180);
        }
        printf("%.9f %.9f %.9f\n",xans,yans,zans);
    }
    return 0;
}
