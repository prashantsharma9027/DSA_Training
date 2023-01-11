#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k1 = *max_element(arr, arr + n);
    int k2 = *min_element(arr, arr + n);
    int k = k1 - k2;

    int count[k + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - k2]++;
    }
    int i = 0;
    int j = 0;
    int l = 0;
    while (i <= k)
    {
        // cout << l++ << endl;
        if (count[i] > 0)
        {
            arr[j] = i + k2;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
