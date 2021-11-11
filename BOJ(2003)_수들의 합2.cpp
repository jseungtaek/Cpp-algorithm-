//baekjoon 2003 수들의 합2
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
    int *A;
    int N, M, index, cnt = 0;
    cin >> N >> M;
    A = (int *)malloc(sizeof(int) * N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        sum += A[i];
        if (sum == M) //처음 더하는 수가 M이 될 경우 cnt++ 후 다시 for문을 실행하도록 continue
        {
            cnt++;
            continue;
        }
        for (int j = i + 1; j <= N; j++)
        {
            sum += A[j];
            if (sum == M)
            {
                cnt++;
                break;
            }
            else if (sum > M) //M보다 크면 의미가 없으므로 break
                break;
        }
    }
    free(A);
    cout << cnt;
    return 0;
}