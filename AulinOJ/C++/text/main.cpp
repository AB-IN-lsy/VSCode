#include <bits/stdc++.h>

using namespace std;

int main()
{
  char str1[999],str2[999];
  int i,j,flag=0,m;
  cin.getline(str1,sizeof(str1));
  cin>>str2[0]>>str2[1];
  if(str2[0]!='D')
    cin>>str2[2];
  if(str2[0]=='D')
  {
      for(i=0;i<sizeof(str1);i++)
      {
          if(str1[i]==str2[1])
          {
              flag=1;
              for(j=i;str1[j]!='.';j++)
                str1[j]=str1[j+1];
          }
          if(flag)
            break;
      }
  }
  if(str2[0]=='I')
  {
      flag=0;
       for(i=sizeof(str1)-1;i>=0;i--)
      {
          if(str1[i]==str2[1])
          {
              flag=1;
              for(j=sizeof(str1)-1;j>=i;j--)
              {
                str1[j]=str1[j-1];
              }
              str1[i]=str2[2];
          }
          if(flag)
            break;
      }
  }
  if(str2[0]=='R')
  {
       for(i=0;i<sizeof(str1);i++)
      {
          if(str1[i]==str2[1])
          {
              flag=1;
              str1[i]=str2[2];
          }
      }
  }
  if(flag)
  {for(i=0;str1[i]!='.';i++)
    cout<<str1[i];
  cout<<".";}
  else
    cout<<"Not exist";


    return 0;
}
