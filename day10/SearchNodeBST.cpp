#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    if (k < root->data)
    {
        return searchInBST(root->left, k);
    }
    else
    {
        return searchInBST(root->right, k);
    }
}

//iterative approach
bool searchInBST2(BinaryTreeNode<int> *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return true;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}


int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    int k;
    cin >> k;
    cout << ((searchInBST2(root, k)) ? "true" : "false");
    delete root;

    return 0;
}
