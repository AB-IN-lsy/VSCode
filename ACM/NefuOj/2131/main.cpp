#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int maxn = 1e6 + 5;
char s[maxn];
int Next[maxn];
int main()
{
    while (~scanf("%s", s))
    {
        if (s[0] == '.')
            break;
        int len = strlen(s);
        memset(Next, 0, sizeof(Next));
        int i = 0, j = -1;
        Next[0] = -1;   //s[i]�����׺��s[j]����ǰ׺
        while (i < len) //next����Ϊ���ǰ׺==��׺
        {
            if (j == -1 || s[i] == s[j])
            {
                i++;
                j++;
                Next[i] = j;
            }
            else
                j = Next[j];
        }
        if (len % (len - Next[len]) == 0)            //�����i-1λΪ��β��ѭ���ض��� i % (i - Next[i]) == 0
            printf("%d\n", len / (len - Next[len])); //0��i-1����i���ַ���i / (i - Next[i])����ѭ��������
        else
            printf("1\n");
    }
    return 0;
}
