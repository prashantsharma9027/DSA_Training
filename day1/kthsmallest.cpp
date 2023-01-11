#include <bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int *input, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (input[i] < pq.top())
        {
            pq.pop();
            pq.push(input[i]);
        }
    }
    vector<int> output;
    while (!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}
int main()
{
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    int k;
    cin >> k;
    vector<int> output = kSmallest(input, size, k);

    sort(output.begin(), output.end());
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << " ";
    // }
    cout << output[k - 1];
    
    delete[] input;
    return 0;
}
