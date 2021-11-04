//baekjoon 1316 그룹 단어 체커
#include <iostream>
#include <string.h>

int check_word(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = strlen(str) - 1; j >= 0; j--)
        {
            if (str[i] == str[j])
            {
                int l = i;
                int r = j;
                for (int k = i; k < j; k++)
                {
                    if (str[k] != str[k + 1])
                        return 0;
                }
            }
        }
    }
    return 1;
}

int main(void)
{
    char str[102];
    char word;
    int N, cnt = 0;

    std::cin >> N;
    for (int m = 0; m < N; m++)
    {
        std::cin >> str;
        if (check_word(str))
            cnt++;
    }
    std::cout << cnt;
    return 0;
}