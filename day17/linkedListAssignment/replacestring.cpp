#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node()
    {
        data = "";
        next = NULL;
    }

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{

public:
    Node *head;
    Linkedlist() { head = NULL; }

    void insertNode(string);

    void printList();

    void replaceNode(string, string);

    void deleteNodeIndex(int);

    void insertNodeIndex(string, int);
};

void Linkedlist::replaceNode(string nodeOffset, string newStr)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == nodeOffset)
        {
            temp->data = newStr;
        }
        temp = temp->next;
    }
}

void Linkedlist::deleteNodeIndex(int index)
{
    Node *temp = head;
    Node *prev = head;
    while (index--)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = prev->next->next;
    return;
}

void Linkedlist::insertNode(string data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = newNode;
}

void Linkedlist::insertNodeIndex(string data, int index)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    Node *prev = new Node(data);
    while (index--)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = newNode;
    newNode->next = temp;

    return;
}

void Linkedlist::printList()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void print(Node *temp)
{

    if (temp == NULL)
    {
        cout << "List empty" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Linkedlist list;

    list.insertNode("hello");
    list.insertNode("I");
    list.insertNode("am");
    list.insertNode("Prashant");
    list.insertNode("in");
    list.insertNode("5th");
    list.insertNode("semester");
    list.insertNode("in");
    list.insertNode("kargil");
    list.insertNode("batch");
    list.insertNode("in");
    list.insertNode("CU");

    cout << "Replace The String with Other String: " << endl;

    list.printList();
    cout << endl
         << endl;

    list.replaceNode("5th", "6th");
    cout << "After replacing '5th' with '6th' we get String as: " << endl
         << endl;

    list.printList();
    cout << endl;

    cout << endl;
    return 0;
    
}
