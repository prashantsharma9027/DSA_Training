#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

// insert in max heap 

BinaryTreeNode<int> *insertHeap(BinaryTreeNode<int> *root, int data)
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
    cout<<endl;

    // insert new node at last
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
    v.push_back(newNode);

    // swap with parent if parent is smaller
    int childIndex = v.size() - 1;
    while (childIndex > 0)
    {
        int parentIndex = (childIndex - 1) / 2;
        if (v[childIndex]->data > v[parentIndex]->data)
        {
            swap(v[childIndex], v[parentIndex]);
        }
        else
        {
            break;
        }
        childIndex = parentIndex;
    }
    v[v.size() - 1]->left = NULL;
    v[v.size() - 1]->right = NULL;
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

    cout << "Before Insertion" << endl;
    printLevelorder(root);

    root = insertHeap(root, 100);
    cout << "After Insertion" << endl;

    printLevelorder(root);
    return 0;
}
