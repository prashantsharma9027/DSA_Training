#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {12, 18, 11, 20};

    cout << arr << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;

    int *p = &arr[1];

    cout << p << endl;  // address of arr[0]
    cout << *p << endl; // value of p at arr[0]
    cout << &p << endl; // address of p -- it's not address of arr

    return 0;
}
