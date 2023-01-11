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
    int mx = *max_element(arr, arr + n);

    int maxdigit = 0;
    while (mx > 0)
    {
        mx /= 10;
        maxdigit++;
    }
    // cout << maxdigit << endl;

    //radix sort
    int exp = 1;
    int count[10] = {0};
    int output[n];
    for (int i = 0; i < maxdigit; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count[(arr[j] / exp) % 10]++;
        }
        for (int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }
        for (int j = n - 1; j >= 0; j--)
        {
            output[count[(arr[j] / exp) % 10] - 1] = arr[j];
            count[(arr[j] / exp) % 10]--;
        }
        for (int j = 0; j < n; j++)
        {
            arr[j] = output[j];
        }
        exp *= 10;
        for (int j = 0; j < 10; j++)
        {
            count[j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}
