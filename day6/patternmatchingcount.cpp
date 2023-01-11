#include <bits/stdc++.h>
using namespace std;
int main(){
    string str= "abcdaaabcccdabccccd";
    int n = str.length();
    string pat= "ccc";
    int m = pat.length();
    int count[256] = {0};
    for(int i=0;i<m;i++){
        count[pat[i]]++;
    }
    int i=0;
    int j=0;
    int k=m;
    while(i<n){
        if(count[str[i]]>0){
            count[str[i]]--;
            k--;
            i++;
        }
        else{
            count[str[j]]++;
            k++;
            j++;
        }
        if(k==0){
            cout<<"Pattern found at index "<<j<<endl;
        }
    }

return 0;
}
