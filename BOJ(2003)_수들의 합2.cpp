//baekjoon 2003 ������ ��2
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
        if (sum == M) //ó�� ���ϴ� ���� M�� �� ��� cnt++ �� �ٽ� for���� �����ϵ��� continue
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
            else if (sum > M) //M���� ũ�� �ǹ̰� �����Ƿ� break
                break;
        }
    }
    free(A);
    cout << cnt;
    return 0;
}