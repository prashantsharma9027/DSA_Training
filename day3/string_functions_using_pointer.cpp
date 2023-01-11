#include <bits/stdc++.h>
using namespace std;

// string functions using pointer
// length
int length(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
    }
    return i;
}
// copy
void copy(char *str, char *str2)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        *(str2 + i) = *(str + i);
        i++;
    }
    *(str2 + i) = '\0';
}
// reverse
void reverse(char *str)
{
    int i = 0;
    int j = length(str) - 1;
    while (i < j)
    {
        swap(*(str + i), *(str + j));
        i++;
        j--;
    }
}
// concatenate
void concatenate(char *str, char *str2)
{
    int i = length(str);
    int j = 0;
    while (*(str2 + j) != '\0')
    {
        *(str + i) = *(str2 + j);
        i++;
        j++;
    }
    *(str + i) = '\0';
}

int main()
{

    char str[50];
    char str2[50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    str[n] = '\0';
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> str2[i];
    }
    str2[n2] = '\0';

    cout << "length of str1" << endl;
    cout << length(str) << endl;
    cout << "length of str2" << endl;
    cout << length(str2) << endl;

    copy(str, str2);
    cout << "strings after copying" << endl;

    cout << str << endl;
    cout << str2 << endl;

    // reverse(str);
    // cout << "reverse of str:1" << endl;
    // cout << str << endl;

    // cout << "concatenate str:1 and str:2" << endl;
    // concatenate(str, str2);

    // cout << str << endl;

    // copy reverse concatenate
    return 0;
}
