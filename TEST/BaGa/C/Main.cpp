#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

int main()
{
    node *list = new node;
    node *head = list;
    node *a1 = new node;
    node *a2 = new node;
    node *a3 = new node;
    a1->data = 7;
    a2->data = 25;
    a3->data = 35;
    a1->next = a2;
    a2->next = a3;
    a3->next = nullptr;
    node *b1 = new node;
    node *b2 = new node;
    node *b3 = new node;
    b1->data = 6;
    b2->data = 9;
    b3->data = 14;
    b1->next = b2;
    b2->next = b3;
    b3->next = nullptr;
    node *p1 = a1;
    node *p2 = b1;
    node *temp = a1;
    cout << "======链表1======" << endl;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "======链表2======" << endl;
    temp = b1;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->data < p2->data)
        {
            list->next = p1;
            p1 = p1->next;
            // cout << "1"
            //      << " ";
        }
        else
        {
            list->next = p2;
            p2 = p2->next;
            // cout << "2"
            //      << " ";
        }
        list = list->next;
    }
    if (p1 != nullptr)
    {
        list->next = p1;
    }
    else
    {
        list->next = p2;
    }
    cout << "======链表合======" << endl;
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}