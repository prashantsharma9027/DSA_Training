#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *inputTillNegativeOne()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *Rinsert(int data, int position, Node *head)
{
    if (!head)
    {
        return head;
    }
    if (position == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    else
    {
        Node *temp = Rinsert(data, position - 1, head->next);
        head->next = temp;
        return head;
    }
}
int getLength(Node *head)

{

    Node *temp = head;
    int size = 0;
    temp = head;

    while (temp)
    {
        // cout << temp->data << " ";
        temp = temp->next;
        size++;
    }
    return size;
}
Node *separateevenodd(Node *head)
{
    Node *odd = NULL;
    Node *even = NULL;
    Node *oddtail = NULL;
    Node *eventail = NULL;
    Node *temp = head;
    while (temp)
    {
        if ((temp->data) % 2 == 0)
        {
            if (!even)
            {
                even = temp;
                eventail = temp;
            }
            else
            {
                eventail->next = temp;
                eventail = temp;
            }
        }
        else
        {
            if (!odd)
            {
                odd = temp;
                oddtail = temp;
            }
            else
            {
                oddtail->next = temp;
                oddtail = temp;
            }
        }
        temp = temp->next;
    }
    if (odd)
    {
        oddtail->next = even;
        eventail->next = NULL;
        return odd;
    }
    else
    {
        eventail->next = NULL;
        return even;
    }
}
Node *getMiddleTwoPointer(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *previous = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return previous;
}
Node *mergeWithoutExtraSpace(Node *head1, Node *head2)
{
    Node *tail = NULL;
    Node *current1 = head1;
    Node *current2 = head2;
    if (current1->data < current2->data)
    {
        head1 = current1;
        tail = current1;
        current1 = current1->next;
    }
    else
    {
        head1 = current2;
        tail = current2;
        current2 = current2->next;
    }
    while (current1 && current2)
    {
        if (current1->data < current2->data)
        {
            tail->next = current1;
            current1 = current1->next;
        }
        else
        {
            tail->next = current2;
            current2 = current2->next;
        }
        tail = tail->next;
    }
    if (current1)
    {
        tail->next = current1;
        // current1 = current1->next;
    }
    if (current2)
    {
        tail->next = current2;
        // current2 = current2->next;
    }
    return head1;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *result = new Node(0);
    Node *curr = result;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if (head1 != NULL)
    {
        curr->next = head1;
    }
    else
    {
        curr->next = head2;
    }
    Node *newHead = result->next;
    delete result;
    return newHead;
}

Node *mergesort(Node *head1)
{
    if (head1 && head1->next)
    {
        Node *head2 = NULL;
        Node *mid = getMiddleTwoPointer(head1);
        // if (mid)
        {
            head2 = mid->next;
            mid->next = NULL;
        }
        head1 = mergesort(head1);
        head2 = mergesort(head2);
        head1 = mergeWithoutExtraSpace(head1, head2);
        // head1 = head1->next;
        return head1;
    }
    return head1;
}
Node *rReverseN(Node *head)
{
    if (head && head->next)
    {
        Node *smallAns = rReverseN(head->next);
        Node *tail = head->next;

        tail->next = head;
        head->next = NULL;
        return smallAns;
    }

    return head;
}

int main()
{
    // Node *head = new Node(10);
    // head = Rinsert(20, 1, head);
    // head = Rinsert(30, 2, head);

    Node *head1 = inputTillNegativeOne();
    // Node *head2 = inputTillNegativeOne();

    print(head1);
    int size = getLength(head1);
    cout << size << endl;

    // merge without extra space
    //  head1 = mergeWithoutExtraSpace(head1, head2);
    // print(head1);
    // head = separateevenodd(head);
    head1 = mergesort(head1);
    print(head1);

    //reverse linked list
    head1 = rReverseN(head1);
    // print(head1);



    return 0;
}
