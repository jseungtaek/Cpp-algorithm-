//baekjoon 23303 이 문제는 D2 입니다
#include <iostream>
#include <stdlib.h>
using namespace std;

void print_d2(char *str)
{
    int i = 0;
    while (str[i])
    {
        if ((str[i] == 'D' || str[i] == 'd') && str[i + 1] == '2')
        {
            cout << "D2";
            return;
        }
        i++;
    }
    cout << "unrated";
    return;
}
int main(void)
{
    char *str;
    int i = 0;
    str = (char *)malloc(sizeof(char) * 10002);
    cin.getline(str, 10002);
    print_d2(str);
    free(str);
    return 0;
}