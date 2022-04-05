//baekjoon BOJ(9012) °ýÈ£
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int check(char *str)
{
    stack<char> st;
    while (!st.empty())
        st.pop();
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            if (!st.empty())
                st.pop();
            else
                return 0;
        }
    }
    return st.empty();
}

int main(void)
{
    char str[52];
    int T;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> str;
        if (check(str))
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}