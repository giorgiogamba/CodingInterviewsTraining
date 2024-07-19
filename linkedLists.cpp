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

// Remove the duplicates from the list without using a memory buffer
void removeDuplicatesNoBuffer(LinkedListNode* node)
{
    // Inefficient solution since the list is unsorted
    LinkedListNode* runner = nullptr;
    while (node->next != nullptr)
    {
        runner = node;
        while (runner->next != nullptr)
        {
            if (runner->next->val == node->val)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }

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
    LinkedListNode tmp3(2);
    tmp2.next = &tmp3;
    LinkedListNode tmp4(4);
    tmp3.next = &tmp4;

    removeDuplicatesNoBuffer(&head);
    printList(&head);

    return 0;
}