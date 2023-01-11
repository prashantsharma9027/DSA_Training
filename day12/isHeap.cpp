#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

//is max heap

bool isMaxHeap(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return true;
    }
    if (root->left && root->data < root->left->data)
    {
        return false;
    }
    if (root->right && root->data < root->right->data)
    {
        return false;
    }
    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    cout << isMaxHeap(root);
    return 0;
}
