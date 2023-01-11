#include <bits/stdc++.h>
using namespace std;
int sum = 0;
int getsum(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return getsum(x % 10 + getsum(x / 10));
}
int main()
{

    int x = 678;
    int sum = 0;

    sum = getsum(x);
    cout << sum << endl;

    return 0;
}
