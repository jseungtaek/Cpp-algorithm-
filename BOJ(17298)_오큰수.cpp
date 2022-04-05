//baekjoon 17298 ��ū��
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main(void)
{
    int N, i, j;
    stack<int> arr;
    int *num;
    int *res;

    cin >> N;
    num = (int *)malloc(sizeof(int) * N);
    res = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    for (i = N - 1; i >= 0; i--)
    {
        while (!arr.empty() && arr.top() <= num[i]) //��ū���� ���� ���� �Ǻ�
        {
            arr.pop();
        }
        if (arr.empty()) //��� �ִٸ� �迭�� �ش� index�� ��ū���� �������� ����
            res[i] = -1;
        else //������� �ʴٸ� ��ū���� �����ϹǷ� stack�� ���� top index ��
            res[i] = arr.top();
        arr.push(num[i]); //stack�� �װ� ��
    }
    for (i = 0; i < N; i++)
        cout << res[i] << " ";
    return 0;
}