#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

// delete in max heap

BinaryTreeNode<int> *deleteHeap(BinaryTreeNode<int> *root)
{
    // get level order in vector
    vector<BinaryTreeNode<int> *> v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        v.push_back(front);
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i]->data << " ";
    }
    cout << endl;
// return 0;
    // swap last node with root
    swap(v[0], v[v.size() - 1]);

    // delete last node

    // delete v[v.size() - 1];
    v.pop_back();

    // swap with larger child if parent is smaller
    int parentIndex = 0;
    while (parentIndex < v.size())
    {
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int maxIndex = parentIndex;
        if (leftChildIndex < v.size() && v[leftChildIndex]->data > v[maxIndex]->data)
        {
            maxIndex = leftChildIndex;
        }
        if (rightChildIndex < v.size() && v[rightChildIndex]->data > v[maxIndex]->data)
        {
            maxIndex = rightChildIndex;
        }
        if (maxIndex == parentIndex)
        {
            break;
        }
        swap(v[maxIndex], v[parentIndex]);
        parentIndex = maxIndex;
    }

    // make tree from vector
    for (int i = 0; i < v.size(); i++)
    {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;
        if (leftChildIndex < v.size())
        {
            v[i]->left = v[leftChildIndex];
        }
        if (rightChildIndex < v.size())
        {
            v[i]->right = v[rightChildIndex];
        }
    }
    return v[0];
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();

    cout << "Before deletion" << endl;
    printLevelorder(root);

    root = deleteHeap(root);
    cout << "After deletion" << endl;

    printLevelorder(root);
    return 0;
}
