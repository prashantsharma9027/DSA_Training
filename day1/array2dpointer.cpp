#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mat[4][5];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int *ptr = mat[0];
    int **ptr2 = &ptr;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << i << " " << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << j << " " << endl;
            cout<<*(*(ptr2 + i) + j)<<" "<<endl;
            // cout << j << " " << endl;
            sum += *(*(ptr2 + i) + j);
        }
    }
    cout << sum << endl;

    return 0;
}
