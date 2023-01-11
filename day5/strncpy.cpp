#include <bits/stdc++.h>
using namespace std;

// compare strings of length n
int length(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
    }
    return i;
}

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

void ncopy(char *str, char *str2, int n)
{
    int i = 0;
    while (*(str + i) != '\0' && i < n)
    {
        *(str2 + i) = *(str + i);
        i++;
    }
    // *(str2 + i) = '\0';
}

int main()
{
    char str[50];
    char str2[50];

    // get string input using char array
    cin.getline(str, 50);
    cout << str << endl;
    cin.getline(str2, 50);
    cout << str2 << endl;

    // compare strings
    ncopy(str, str2, 3);
    cout << str << endl;
    cout << str2 << endl;
    // cout<<strncmp(str,str2,3)<<endl;
    // cout << ncompare(str, str2, 3) << endl;

    return 0;
}
