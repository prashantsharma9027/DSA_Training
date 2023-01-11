#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

void preOrderPrint(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

BinaryTreeNode<int> *makeTree(vector<int> input, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int> *left = makeTree(input, start, mid - 1);
    BinaryTreeNode<int> *right = makeTree(input, mid + 1, end);
    root->left = left;
    root->right = right;
    return root;
}
BinaryTreeNode<int> *constructTree(vector<int> input, int n)
{
    return makeTree(input, 0, n - 1);
}

void inOrder2(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }
    inOrder2(root->left,v);
    // cout << root->data << " ";
    v.push_back(root->data);
    inOrder2(root->right,v);
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    vector<int> v;
    inOrder2(root, v);
    int size = v.size();
    // int *input = new int[size];
    // for (int i = 0; i < size; i++)
    // {
    //     input[i] = v[i];
    // }


    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    BinaryTreeNode<int> *root2 = constructTree(v, size);
    inOrder(root2);
    cout << endl;
    // printLevelorder(root2);

    preOrderPrint(root2);

    return 0;
}
