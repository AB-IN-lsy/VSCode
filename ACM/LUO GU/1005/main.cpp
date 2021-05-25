#include<iostream>
using namespace std;
int n,x,ans,cnt,cnt1=1,ans1=1;
char c;
int main()
{
	while(cin>>n){
		ans=n;
		while(cin>>c&&c!='Q'){
			cin>>x;
			ans=ans-x;
			cnt++;
		}
		ans++;//Î»ÖÃ
		for(int i=1;i<=ans;i++){
            ans1=ans1*i;
		}
		for(int i=1;i<=ans-cnt;i++){
            cnt1=cnt1*i;
		}
		cout<<ans1/cnt1;
	}

	return 0;
}
