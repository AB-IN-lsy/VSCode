#include <iostream>

using namespace std;

int main()
{
    ///1.1.array3
    int i=0;
    float a[10],n;
    FILE *fp=NULL;
    fp=fopen("array3.txt","r");
    while(fscanf(fp,"%f",&n)!=EOF) i++,a[i]=n;
    for(int j=1;j<=i;j++) printf("%.1f ",a[j]);


    ///2
    int num=0;
    freopen("write.txt","w",stdout);
    for(int i=1;i<=10;i++) scanf("%d",&num),printf("%d ",num);

    return 0;
}
