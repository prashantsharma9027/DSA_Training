#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node()
    {
    }
    Node(char data)
    {
        this->data = data;
        this->next = NULL;
    }
};
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
Node *inputTillNegativeOne()
{
    char data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != '0')
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
bool isEqual(Node *head1, Node *head2)
{
    Node *temp = head1;
    Node *temp2 = head2;
    bool flag = true;
    while (temp && temp2)
    {
        if (!temp || !temp2)
        {
            flag = true;
            break;
        }
        if (temp->data != temp2->data)
        {
            // cout << temp->data << " " << temp2->data;
            flag = false;
            break;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    return flag;
}

int main()
{
    // Node *head = new Node(10);
    // head = Rinsert(20, 1, head);
    // head = Rinsert(30, 2, head);

    Node *head1 = inputTillNegativeOne();
    // Node *head2 = inputTillNegativeOne();

    // print(head1);
    // int size = getLength(head1);
    // cout << size << endl;

    // merge without extra space
    //  head1 = mergeWithoutExtraSpace(head1, head2);
    // print(head1);
    // head = separateevenodd(head);
    // head1 = mergesort(head1);
    // print(head1);

    // reverse linked list
    Node *head2 = rReverseN(head1);
    print(head2);
    bool flag = isEqual(head1, head2);
    if (flag)
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not palindrome";
    }

    return 0;
}
