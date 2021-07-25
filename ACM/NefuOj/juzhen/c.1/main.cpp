#include <iostream>

using namespace std;
inline int f(int x) {
	if (x == 1 || x == 2) return 1;
	else return f(x - 1) + f(x - 2);
};
int main()
{
    for(int i=1;i<=200;i++){
        if(f(2*i)%8==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
