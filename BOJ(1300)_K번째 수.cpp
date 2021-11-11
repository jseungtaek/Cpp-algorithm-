//baekjoon 1300 K��° ��
#include <iostream>
#include <algorithm>
//�̺�Ž�� �˰��� ����
using namespace std;
int main(void)
{
    int N, k, st = 1, fi, mid, result = 0;
    cin >> N >> k;
    fi = k;
    while (st <= fi)
    {
        mid = (st + fi) / 2;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(mid / i, N); //mid/i ���� �ش� �࿡�� mid���� ���� ������ �� �� �ִ�. ���� �࿡�� mid���� �۰ų� ���� ���ڴ� min(mid / i , N)���� ���� �� ����
        }
        if (cnt >= k) //mid���� �۰ų� ���� ���� k�� ���� ũ�ų� ������ result = mid, finish�� mid + 1
        {
            result = mid;
            fi = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    cout << result;
    return 0;
}