//baekjoon 12904 A�� B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//S -> T�� ������ T -> S�� ���� �� �ִ��� ���θ� �ľ�
int main(void)
{
    string s, t;
    int flag = 0;
    cin >> s >> t;
    while (!flag && t.size() != 0) //while Ż���� ���� ���ǹ� (flag == 1 �̸� t�� s�� ���� �� ������ �ǹ�) (���� ������ t�� pop�Ǿ� ���̻� pop�� ���ڰ� ������ ����)
    {
        if (s.size() == t.size())
        {
            if (s == t)
                flag = 1;
        }
        if (t[t.size() - 1] == 'A') //�� ���ڰ� A��� pop
            t.pop_back();
        else //�� ���ڰ� B��� pop �� ���� ������
        {
            t.pop_back();
            reverse(t.begin(), t.end()); //algorithm header�� �ִ� reverse
        }
    }
    cout << flag;
    return 0;
}