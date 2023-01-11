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

class DoubleNode
{
public:
    int data;
    DoubleNode *next;
    Node *down;
    DoubleNode()
    {
    }
    DoubleNode(int data)
    {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};
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

int main()
{

    DoubleNode *head = NULL;
    DoubleNode *righttail = NULL;
    cout << "Enter the size of the double linked list" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data of the double node" << endl;
        int data;
        cin >> data;
        DoubleNode *newDoubleNode = new DoubleNode(data);
        if (!head)
        {
            head = newDoubleNode;
            righttail = newDoubleNode;
        }
        else
        {
            righttail->next = newDoubleNode;
            righttail = newDoubleNode;
        }
        cout << "Enter the size of the singly linked list" << endl;
        int k;
        cin >> k;
        Node *tail = NULL;
        for (int j = 0; j < k; j++)
        {
            cout << "Enter the data of the singly node" << endl;

            int data;
            cin >> data;
            Node *newNode = new Node(data);
            if (!righttail->down)
            {
                righttail->down = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    // flatten linked list

    // print the linked list
      DoubleNode *temp = head;
      Node *head1 = NULL;
      head1 = temp->down;
      while (temp && temp->next)
      {
          // cout<<"double node data is "<<temp->data<<endl;
          cout << temp->data << " ";
          while (head1->next)
          {
              cout << head1->data << " ";
              head1 = head1->next;
          }
          cout << head1->data << " ";
          // cout << head1->data << " ";
          head1= temp->next->down;
          temp = temp->next;
          cout << endl;
      }
      // cout << "double node data is " << temp->data << endl;
      cout << temp->data << " ";

      while (head1->next)
      {
          cout << head1->data << " ";
          head1 = head1->next;
      }

    // merge sort
    /* DoubleNode *temp = head;
    Node *head1 = NULL;
    // newnode having double node data
    Node *singlehead = new Node(temp->data);
    Node *singletail = singlehead;
    singletail->next = temp->down;
    while (temp && temp->next)
    {
        while (singletail->next)
        {
            singletail = singletail->next;
        }

        Node *newnode = new Node(temp->next->data);
        singletail->next = newnode;
        singletail = newnode;
        singletail->next = temp->next->down;
        temp = temp->next;
    }
    print(singlehead);
    cout << endl;
    head1 = mergesort(singlehead);
    print(singlehead); */

    // head1 = temp->down;

    return 0;
}
