
#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node()
    {
        data = ' ';
        next = NULL;
    }

    Node(char data)
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

    void insertNode(char);

    void printList();

    void deleteNode(char);

    void deleteNodeIndex(int);

    void insertNodeIndex(char, int);
};

void Linkedlist::insertNode(char data)
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

bool isCharacterPresent(Node *head, char x)
{
    if (head == NULL)
        return false;

    while (head)
    {
        if (tolower(head->data) == tolower(x))
            return true;
        head = head->next;
    }
    return false;
}

int main()
{
    Linkedlist list;

    list.insertNode('P');
    list.insertNode('R');
    list.insertNode('A');
    list.insertNode('S');
    list.insertNode('H');
    list.insertNode('A');
    list.insertNode('N');
    list.insertNode('T');

    cout << "Check if Character Present or not: " << endl;

    list.printList();
    cout << endl;

    cout << "Check if 'P' is Present or not" << endl;
    if (isCharacterPresent(list.head, 'P'))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    cout << endl;
    return 0;
}
