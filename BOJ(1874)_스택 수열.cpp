//baekjoon 1874 스택 수열
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    stack<int> num;
    vector<char> op;
    int n, cnt = 1, order;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> order;
        while (cnt <= order)
        {
            num.push(cnt);
            cnt++;
            op.push_back('+');
        }
        if (num.top() == order)
        {
            num.pop();
            op.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < op.size(); i++)
        cout << op[i] << "\n";
    return 0;
}