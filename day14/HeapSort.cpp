#include <bits/stdc++.h>
using namespace std;

void buildHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
/*     for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */
}
void removeMin(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        int min = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = min;
        size--;

        int parentIndex = 0;
        while (parentIndex < size)
        {
            int leftChildIdx = 2 * parentIndex + 1;
            int rightChildIdx = 2 * parentIndex + 2;
            int minIndex = -1;
            if (leftChildIdx < size && rightChildIdx < size)
            {
                if (arr[leftChildIdx] < arr[rightChildIdx])
                {
                    minIndex = leftChildIdx;
                }
                else
                {
                    minIndex = rightChildIdx;
                }
            }
            else if (leftChildIdx < size)
            {
                minIndex = leftChildIdx;
            }
            else if (rightChildIdx < size)
            {
                minIndex = rightChildIdx;
            }
            if (minIndex != -1 && arr[parentIndex] > arr[minIndex])
            {

                swap(arr[parentIndex], arr[minIndex]);
               

                parentIndex = minIndex;
            }
            else
            {
                break;
            }
        }
    }
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    removeMin(arr, n);
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
    heapSort(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    delete[] input;

    return 0;
}
