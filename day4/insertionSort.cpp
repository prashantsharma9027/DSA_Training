#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // the empty cell
    {
        int j = i - 1;
        int x = arr[i];              // since arr[i] changes, we should take out the value
        while (j > -1 && arr[j] > x) // not out of range and greater
        {
            arr[j + 1] = arr[j]; // shift
            j--;
        }
        arr[j + 1] = x; // virtually empty index, for insertion
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
