//baekjoon 12904 A와 B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//S -> T를 역으로 T -> S로 만들 수 있는지 여부를 파악
int main(void)
{
    string s, t;
    int flag = 0;
    cin >> s >> t;
    while (!flag && t.size() != 0) //while 탈출을 위한 조건문 (flag == 1 이면 t로 s를 만들 수 있음을 의미) (종료 조건은 t가 pop되어 더이상 pop할 문자가 없으면 종료)
    {
        if (s.size() == t.size())
        {
            if (s == t)
                flag = 1;
        }
        if (t[t.size() - 1] == 'A') //끝 문자가 A라면 pop
            t.pop_back();
        else //끝 문자가 B라면 pop 후 문자 뒤집기
        {
            t.pop_back();
            reverse(t.begin(), t.end()); //algorithm header에 있는 reverse
        }
    }
    cout << flag;
    return 0;
}