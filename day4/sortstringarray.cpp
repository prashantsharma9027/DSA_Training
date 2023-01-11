#include <bits/stdc++.h>
using namespace std;
int compare(char *str, char *str2)
{
    int i = 0;
    while (*(str + i) != '\0' && *(str2 + i) != '\0')
    {
        if (*(str + i) < *(str2 + i))
        {
            return 0;
        }
        i++;
    }
    if (*(str + i) == '\0' && *(str2 + i) == '\0')
    {
        return 1;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    char str[n][50];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(str[i], str[j]) > 0){
                swap(str[i], str[j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << str[i] << endl;
    }
return 0;
}
