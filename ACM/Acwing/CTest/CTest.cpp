/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-25 20:05:38
 * @FilePath: \Acwing\CTest\CTest.cpp
 * @LastEditTime: 2022-12-26 18:38:54
 */
#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

class Person
{
    int age;

  public:
    string name;

    int gender;
};

struct Node
{

    int val;
    Node *next;

    Node(int _val) : val(_val), next(NULL)
    {
    }
};

struct stu
{
    char name[10];
    int age;
    int sex;
} s[5], *p = s;

void f(int *q, int n)
{
    for (int i = 0; i < n; ++i)
        (*(q++))++;
}

// struct node{
//     int data;
//     struct node *next;
// };

typedef struct
{
    int num, score;
} STU;

// #define fun(x) x *x

signed main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    cout << ++*p;
    cout << ++*p;
    // int m = 1, n = 2, k = 3, a, b, c;
    // int sum = fun(m + n) * k;
    // a = (b = 4) / (c = 2);
    // cout << (a = 4);
    // double x = 3.1415;
    // x = (x * 100 + 0.5) / 100.0;
    // cout << x;

    // STU a[5] = {{1001, 88}, {1002, 82}, {1003, 73}, {1004, 95}, {1005, 80}}, *p[5], *t;
    // for (int i = 0; i < 5; ++i)
    //     p[i] = &a[i];
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5 - i - 1; j++)
    //         if (p[j]->score > p[j + 1]->score)
    //         {
    //             t = p[j];
    //             p[j] = p[j + 1];
    //             p[j + 1] = t;
    //         }
    // }
    // for (int i = 0; i < 5; ++i)
    //     cout << p[i]->score << '\n';
    // cout << a[2].score << " " << p[2]->score;
    // union {
    //     int i;
    //     char c[4];
    // } r, *s = &r;
    // s->i = 0x28D;
    // printf("%x\n", s->c[3]);

    // int k = 5, n = 0;
    // do
    // {
    //     switch (k)
    //     {
    //     case 1:
    //     case 3:
    //         n += 1;
    //         break;
    //     default:
    //         n = 0;
    //     case 2:
    //     case 4:
    //         n += 2;
    //         k--;
    //         break;
    //     }
    //     cout << n;
    // } while (k > 0 && n < 5);

    // int i = 012, j = 12, k = 0x12;
    // cout << i << j << k;

    // int a[10], *p;
    // p = (a + 3);

    // cout << p;
    // int k = 2 < 3 ? 3 : 2;
    // cout << k;
    // struct s
    // {
    //     int n;
    //     int *m;
    // } *p;
    // int f[5] = {100, 200, 300, 400, 500};
    // struct s arr[5] = {10, &f[0], 20, &f[1], 30, &f[2], 40, &f[3], 50, &f[4]};
    // p = arr;
    // printf("%d", ++p->n);
    // printf("%d", (p++)->n);
    // FILE *fp;
    // char fname[20];
    // if ((fp = fopen(fname, "wb")) == NULL)
    // {
    // };

    // int a[5] = {1, 3, 5, 7, 9};
    // f(a, 5);
    // for (int i = 0; i < 5; ++i)
    //     printf("%3d", a[i]);

    // scanf("%d", &(p->age)); // 输入1000，其实就是p+0处的age=1000

    // cout << (p++)->age; 1000
    // cout << (++p)->age; 0

    // union {
    //     short int i[2];
    //     long k;
    //     char c[4];
    // } r, *s = &r;
    // s->i[0] = 0x39;
    // s->i[1] = 0x38;
    // cout << s->i[0] << endl; // 57 即39（16）的十进制
    // cout << s->k << endl; // 3670073

    // Node *p = new Node(1);
    // Node c = Node(1);

    // cout << p << '\n';
    // cout << c.val << endl;

    // char a[] = "ab";
    // char b[] = {'a', 'b'};

    // cout << strlen(a) << endl;
    // cout << strlen(b) << endl;

    // char *l[] = {"kk", "ll"};
    // cout << l[1];

    // char ch;
    // ch = 'A' + '6';
    // cout << ch;

    // enum week_day
    // {
    //     Mon,
    //     Tue
    // };

    // week_day week = Mon;
    // cout << week << '\n';

    // Person lsy;
    // lsy.gender = 1;
    // lsy.name = "liusy";

    // char c2[] = "China";
    // char c3[6] = {'C', 'h', 'i', 'n', 'a'};
    // // char c4[] = {'C', 'h', 'i', 'n', 'a'};

    // cout << c2 << '\n';
    // cout << c3 << '\n';
    // // cout << c4 << '\n';

    // cout << (pow(2, 31) >= (float)1e9) << '\n';

    // char a = 'a';

    // char c3[6] = {'C', 'h', 'i', 'n', 'a'};
    // char c = 'c';

    // cout << (void *)&a << '\n';

    // cout << (void *)&c << '\n';
    // for (int i = 0; i < 6; ++i)
    //     cout << (void *)&c3[i] << '\n';

    // for (int i = 2; i < 7; ++i)
    //     cout << (void *)(&c3[4] + i) << ": " << *(&c3[4] + i) << '\n';

    // cout << (void *)(&c + 1) << ": " << *(&c + 1) << '\n';
    // cout << (void *)(&c + 2) << ": " << *(&c + 2) << '\n';
    // cout << (void *)(&c + 3) << ": " << *(&c + 3) << '\n';

    // int a = 10;
    // int &p = a;

    // printf("%d\n", p);

    // cout << (void *)&p << '\n';
    // cout << (void *)&a << '\n';

    return 0;
}