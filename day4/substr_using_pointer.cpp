#include <bits/stdc++.h>
using namespace std;

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
// substring using char array
char *substring(char *str, int start, int end)
{
    int i = 0;
    char *sub = new char[end - start + 1];
    while (start <= end)
    {
        *(sub + i) = *(str + start);
        i++;
        start++;
    }
    *(sub + i) = '\0';
    return sub;
}

int main()
{
    char str[50];

    // get string input using char array
    cin.getline(str, 50);
    cout << str << endl;
    // get substring using char array
    char sub[50];
    int start, end;
    cin >> start >> end;
    copy(substring(str, start, end), sub);
    cout << sub << endl;

    return 0;
}
