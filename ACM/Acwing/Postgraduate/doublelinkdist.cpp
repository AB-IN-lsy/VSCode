/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-05 19:53:26
 * @FilePath: \Acwing\Postgraduate\doublelinkdist.cpp
 * @LastEditTime: 2022-12-05 20:47:50
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next, *prev;

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
    Node *head = new Node(), *tail = new Node();
    head->next = tail, tail->prev = head;

    // 头插a
    Node *a = new Node(1);
    a->next = head->next, a->prev = head; // 建边
    head->next->prev = a, head->next = a; // 拆边

    auto b = new Node(2);
    b->next = a->next, b->prev = a;
    a->next->prev = b, a->next = b;

    print(head);

    // 删除b
    b->prev->next = b->next;
    b->next->prev = b->prev;
    delete b;
    print(head);

    return 0;
}