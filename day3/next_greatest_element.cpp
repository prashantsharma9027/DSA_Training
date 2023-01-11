#include <bits/stdc++.h>
using namespace std;

vector<int> greaterelements(int *a, int n)
{
   /*  vector<int> v;
    stack<int> s;
    s.push(a[n - 1]);
    // v.push_back(0);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty()  && s.top() <= a[i])
        {
            s.pop();
        }
        int ng = s.empty() ? 0 : s.top();
        v.push_back(ng);
        s.push(a[i]);
    }
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }

    return v; */

//all greater elements on right side
    vector<int> v;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        }
        int ng = s.empty() ? 0 : s.top();
        v.push_back(ng);
        s.push(a[i]);
    }
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }

    return v;

}
int main()
{
    int n;
    cin >> n;
    // count of greater elements
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v = greaterelements(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
