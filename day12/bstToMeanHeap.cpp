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
//min heap
void minHeapify(vector<int> &v, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if (left < n && v[left] < v[min])
    {
        min = left;
    }
    if (right < n && v[right] < v[min])
    {
        min = right;
    }
    if (min != i)
    {
        swap(v[i], v[min]);
        minHeapify(v, min, n);
    }
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    vector<int> v;
    inOrder2(root, v);
    int size = v.size();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        minHeapify(v, i, size);
    }
    return 0;
}
