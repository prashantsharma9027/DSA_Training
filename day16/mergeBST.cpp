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
    BinaryTreeNode<int> *root1 = taktInputLevelorder();
    BinaryTreeNode<int> *root2 = taktInputLevelorder();
    vector<int> v1, v2;

    inOrder2(root1, v1);
    inOrder2(root2, v2);

    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> v3(n1 + n2);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] < v2[j])
        {
            v3[k++] = v1[i++];
        }
        else
        {
            v3[k++] = v2[j++];
        }
    }
    while (i<n1)
    {
        v3[k++] = v1[i++];
    }
    while(j<n2)
    {
        v3[k++] = v2[j++];
    }

    for (int i = 0; i < n1 + n2; i++)
    {
        cout << v3[i] << " ";
    }
    cout<<endl;
    

    return 0;
}
