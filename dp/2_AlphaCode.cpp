/* AlphaCode-Question
Send Feedback
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int num_codes_r(int *arr, int size)
{
    if (size == 0 || size == 1)
        return 1;

    int output = num_codes_r(arr, size - 1);
    if (arr[size - 2] * 10 + arr[size - 1] <= 26)
    {
        output += num_codes_r(arr, size - 2);
    }
    return output;
}

int num_codes_i(int *input, int size)
{
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;
    // forward filling

    for (int i = 2; i <= size; i++)
    {
        output[i] = output[i - 1];
        if (input[i - 2] * 10 + input[i - 1] <= 26)
        {
            output[i] += output[i - 2];
        }
    }
    int ans = output[size];
    delete[] output;
    return ans;
}

int num_codes_memo(int *arr, int size, int *memo)
{

    if (size == 0 || size == 1)
        return 1;

    if (memo[size] > 0)
    {
        return memo[size];
    }

    int output = num_codes_memo(arr, size - 1, memo);
    if (arr[size - 2] * 10 + arr[size - 1] <= 26)
    {
        output += num_codes_memo(arr, size - 2, memo);
    }

    memo[size] = output;
    return output;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
    string n;
        cin >> n;
        if (n == "0")
        {
            return 0;
        }
        int *num_arr = new int[n.size() + 1];
        for (int i = 0; i < n.size(); i++)
        {
            num_arr[i] = n[i] - '0';
        }

        cout << num_codes_i(num_arr, n.length()) << endl;
        // cout << num_codes_memo(arr, n, memo) << endl;
    }
}
