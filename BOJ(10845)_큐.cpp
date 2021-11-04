//baekjoon 10845 ť
#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>
using namespace std;

int main(void)
{
    queue<int> q;
    int N, x;
    char str[6];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        if (!strcmp(str, "push"))
        {
            scanf("%d", &x);
            q.push(x);
        }
        else if (!strcmp(str, "pop"))
        {
            if (!q.empty())
            {
                printf("%d\n", q.front());
                q.pop();
            }
            else
                printf("-1\n");
        }
        else if (!strcmp(str, "size"))
        {
            printf("%d\n", q.size());
        }
        else if (!strcmp(str, "empty"))
        {
            if (!q.empty())
                printf("0\n");
            else
                printf("1\n");
        }
        else if (!strcmp(str, "front"))
        {
            if (!q.empty())
                printf("%d\n", q.front());
            else
                printf("-1\n");
        }
        else if (!strcmp(str, "back"))
        {
            if (!q.empty())
                printf("%d\n", q.back());
            else
                printf("-1\n");
        }
    }
    return 0;
}