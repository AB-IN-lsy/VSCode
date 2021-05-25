#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,s1;
	getline(cin,s);
	s1=s;
	char a,b,c;
	cin>>a;
	int n=s.length();
	int t;
	if(a=='D')
	{
		cin>>b;
		t=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==b)
			{
				break;
			}
			t++;
		}
        for(int i=t+1;i<n;i++)
        {
        	s[i-1]=s[i];
        }
		n--;
        if(s1==s)
        cout<<"Not exist";
        else for(int i=0;i<n;i++)
        cout<<s[i];
	}
	if(a=='I')
	{
		cin>>b>>c;
		t=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==b)
			{
				t=i;
			}
		}
        for(int i=n-1;i>=t;i--)
        {
        	s[i+1]=s[i];
        }
		n++;
		s[t]=c;
		if(s1==s)
        cout<<"Not exist";
        else for(int i=0;i<n;i++)
        cout<<s[i];
	}
	if(a=='R')
	{
		cin>>b>>c;
		t=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==b)
			{
				s[i]=c;
			}
       }
        if(s1==s)
        cout<<"Not exist";
        else for(int i=0;i<n;i++)
        cout<<s[i];
	}
	return 0;
}
