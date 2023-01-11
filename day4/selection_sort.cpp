#include <iostream>
#include <sys/time.h>
#include <bits/stdc++.h>
using namespace std;

void selctionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // n-1 passes
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]); // 1 swap per pass
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selctionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
