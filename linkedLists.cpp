// Base Linked List struct

#include <iostream>

using namespace std;

struct LinkedListNode
{
    int val;
    LinkedListNode* next;

    LinkedListNode(int inVal)
    {
        val = inVal;
        next = nullptr;
    }
};

void printList(LinkedListNode* node)
{
    while (node->next != nullptr)
    {
        cout << node->val << endl;
        node = node->next;
    }
}


int main()
{
    // Create a base LinkedList

    LinkedListNode head(0);
    LinkedListNode tmp1(1);
    head.next = &tmp1;
    LinkedListNode tmp2(2);
    tmp1.next = &tmp2;
    LinkedListNode tmp3(3);
    tmp2.next = &tmp3;
    LinkedListNode tmp4(4);
    tmp3.next = &tmp4;

    printList(&head);

    return 0;
}