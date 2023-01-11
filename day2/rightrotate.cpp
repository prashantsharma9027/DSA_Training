#include <bits/stdc++.h>
using namespace std;
void reverse(int *input, int start, int end)
{
    int i = start, j = end;
    while (i < j)
    {
        swap(input[i], input[j]);
        i++;
        j--;
    }
}
void rotate(int *input, int d, int n)
{
    if (d >= n && n != 0)
    {
        d = d % n;
    }
    else if (n == 0)
    {
        return;
    }

    reverse(input, 0, n - 1);     // reverse the whole array
    reverse(input, 0, d-1); // reverse the first part of the array
    reverse(input, d, n - 1); // reverse the second part of the array

    // could use kn built function to reverse the array
    // //  Reverse all the array elements
    // reverse(Array, Array + N);

    // // Reverse the first k elements
    // reverse(Array, Array + K);

    // // Reverse the elements from K
    // // till the end of the array
    // reverse(Array + K, Array + N);
}

int main(){
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    rotate(arr, x, n); // method 1
    // rotate(arr, x, n); // method 2
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;

    return 0;
}
