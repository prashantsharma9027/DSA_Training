#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *Array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Array[i];
    }
    vector<int> b, c;
    for (int i = 0; i < n; i++)
    {
        if (Array[i] < 0)
            b.push_back(Array[i]);
        else
            c.push_back(Array[i]);
    }
    vector<int> d;
    for (int i = 0; i < b.size(); i++)
    {
        d.push_back(b[i]);
    }
    for (int i = 0; i < c.size(); i++)
    {
        d.push_back(c[i]);
    }


    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}
