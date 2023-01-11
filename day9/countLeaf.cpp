#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

int countLeaf(BinaryTreeNode<int> *ptr)
{
    if (ptr)
    {
        int x = countLeaf(ptr->left);
        int y = countLeaf(ptr->right);
        return (!ptr->left && !ptr->right) ? x + y + 1 : x + y;
    }
    return 0;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelorder();
    cout << countLeaf(root) << endl;
}

