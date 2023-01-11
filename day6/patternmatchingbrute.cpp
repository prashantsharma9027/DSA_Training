#include <bits/stdc++.h>
using namespace std;
int main(){
    string str = "abcdaaabcccdabccccd";
    int n = str.length();
    string pat = "ccc";
    int m = pat.length();

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < m && i + j < n && str[i + j] == pat[j])
        {
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
        }
    }

    return 0;
}
