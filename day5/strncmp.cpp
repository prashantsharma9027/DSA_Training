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

int ncompare(char *str, char *str2, int n)
{
    int n1 = length(str);
    int n2 = length(str2);
    if(n1 < n2){
        n = n1;
    }
    else{
        n = n2;
    }

    int i = 0;
    while (*(str + i) != '\0' && *(str2 + i) != '\0' && i < n)
    {
        if (*(str + i) < *(str2 + i))
        {
            return *(str + i) - *(str2 + i);
        }
        else if (*(str + i) > *(str2 + i))
        {
            return *(str + i) - *(str2 + i);
        }
        i++;
    }
    if (*(str + i) == '\0' && *(str2 + i) == '\0')
    {
        return 0;
    }
    return 0;
}

int compare(char *str, char *str2)
{
    int i = 0;
    while (*(str + i) != '\0' && *(str2 + i) != '\0')
    {
        if (*(str + i) < *(str2 + i))
        {
            return *(str + i) - *(str2 + i);
        }
        else if (*(str + i) > *(str2 + i))
        {
            return *(str + i) - *(str2 + i);
        }
        i++;
    }
    if (*(str + i) == '\0' && *(str2 + i) == '\0')
    {
        return 0;
    }
    return *(str + i) - *(str2 + i);
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
    cout << compare(str, str2) << endl;
    // cout<<strncmp(str,str2,3)<<endl;
    cout << ncompare(str, str2, 3) << endl;

    return 0;
}
