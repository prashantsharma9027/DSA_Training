#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

bool isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL && root->left->data > root->data)
        return false;
    if (root->right != NULL && root->right->data < root->data)
        return false;
    return isBST2(root->left) && isBST2(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    cout << (isBST2(root) ? "true" : "false");

    return 0;
}

