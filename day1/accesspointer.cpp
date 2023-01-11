#include <bits/stdc++.h>
using namespace std;

void cntevod(int cntarray[], int size)
{
    int *ptr = cntarray;

    int **ptr2 = &ptr;

    int cnteven = 0, cntodd = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(*(ptr2 + i)) % 2 == 0)
        {
            cnteven++;
        }
        else
        {
            cntodd++;
        }
    }
    cout << cnteven << " " << cntodd << endl;
}
int main()
{
    int cntarray[] = {27, 33, 42, 96, 14, 24, 33};
    int cnteven = 0, cntodd = 0;

    cntevod(cntarray, 7);

    return 0;
}
