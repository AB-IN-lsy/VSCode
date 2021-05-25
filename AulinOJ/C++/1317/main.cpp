#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,len;
    char a[1024];
    while(gets(a)){
        len=strlen(a);
        for(i=0;i<len;i++){
                if(a[0]=='/'&&a[1]=='/'){
                    break;
                }
                else{
                    for(i=0;i<len;i++){
                        if(a[i]=='/'&&a[i+1]=='/'){
                            break;
                        }
                        else{
                            printf("%c",a[i]);
                        }
                    }
                    printf("\n");
                    break;
                }
        }
    }
}
