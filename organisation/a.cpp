#include<bits/stdc++.h>

using namespace std;

int main(){
	char str[20] = "number 17";
	const char delimiters[2] = " ";
	char *token, *pos;
	long number;
	pos = str;
	cout << "str: " << str << endl;
	cout << "&str: " << &str << endl;
	cout << "*str: " << *str << endl;	
	cout << "pos: " << pos << endl;
	cout << "&pos: " << &pos << endl;
	cout << "*pos: " << *pos << endl;
	token = strsep(&pos, delimiters);
	printf("pos: %s\n", pos);
	printf("*pos: %c\n", *pos);
	printf("str: %s\n", str);
	printf("token: %s\n", token);
	printf("*(token+1): %c\n", *(token+1));
	number = strtol(pos, NULL, 16);

	printf("number: %ld\n", number);
	return 0;
}
