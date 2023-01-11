#include <bits/stdc++.h>
using namespace std;

// compare strings
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
int main()
{
    // char str[50];
    // char str2[50];

    // 2d array of strings
    char str[5][50] = {"apple", "mango", "banana", "guava", "pineapple"};
    //sort strings using bubble sort
    int i = 0;
    int j = 0;
    while (i < 5)
    {
        j = 0;
        while (j < 5)
        {
            if (compare(str[i], str[j]) < 0)
            {
                char temp[50];
                copy(temp, str[i]);
                copy(str[i], str[j]);
                copy(str[j], temp);
            }
            j++;
        }
        i++;
    }
    //2562
    // print sorted strings
    i = 0;
    while (i < 5)
    {
        cout << str[i] << endl;
        i++;
    }

    return 0;
}
