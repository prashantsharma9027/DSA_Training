
#include <bits/stdc++.h>
#include "../BinaryTreeNode.cpp"
using namespace std;

int countNLeaf(BinaryTreeNode<int> *ptr)
{
    if (ptr)
    {
        int x = countNLeaf(ptr->left);
        int y = countNLeaf(ptr->right);
        return (ptr->left || ptr->right) ? x + y + 1 : x + y; // even if one is true, ide est node both deg1 and deg2 considered
    }
    return 0;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelorder();
    cout << countNLeaf(root) << endl;
}
