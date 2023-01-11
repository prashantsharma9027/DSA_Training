
#include <bits/stdc++.h>
using namespace std;
#include "myLinkedlist.cpp"
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = inputTillNegativeOne();
        bool flag=ispalindrome(head);
        if (flag)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << "endl";
    }
    return 0;
}
