/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-05 19:53:26
 * @FilePath: \Acwing\Postgraduate\linklist.cpp
 * @LastEditTime: 2022-12-05 19:59:00
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;

    Node() : next(NULL)
    {
    }
    Node(int _val) : val(_val), next(NULL)
    {
    }
};
void print(Node *head)
{
    for (Node *p = head; p; p = p->next)
    {
        cout << p->val << " ";
    }
    cout << '\n';
}

int main()
{
    Node *head = new Node(1);

    Node *a = new Node(2);
    head->next = a;

    print(head);

    return 0;
}