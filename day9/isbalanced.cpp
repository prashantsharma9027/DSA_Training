#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;
// n*h approach
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) <= 1;
}

void inOrder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    // cout << root->data << " ";
    v.push_back(root->data);
    inOrder(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    vector<int> v;
    inOrder(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    // printLevelorder(root);
    // cout << (isBalanced(root) ? "true" : "false");
    // store inorder in a vector

    return 0;
}
