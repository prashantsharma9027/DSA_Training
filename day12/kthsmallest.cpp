#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

void inOrder2(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }
    inOrder2(root->left, v);
    // cout << root->data << " ";
    v.push_back(root->data);
    inOrder2(root->right, v);
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
    int k = 3;
    cout << v[k - 1] << endl;

    cout << endl;
    // printLevelorder(root2);

    return 0;
}
