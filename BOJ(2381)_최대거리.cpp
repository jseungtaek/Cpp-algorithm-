//baekjoon 2381 �ִ�Ÿ�
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(void)
{
    int N, *coord_plus_max, *coord_minus_max, x, y, L1_metric;

    cin >> N;
    coord_plus_max = (int *)malloc(sizeof(int) * N);
    coord_minus_max = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        coord_plus_max[i] = x + y;  //(x_1 + y_1) - (x_2 + y_2) �� �ִ� ���ϱ�
        coord_minus_max[i] = x - y; //(x_1 - y_1) - (x_2 - y_2) �� �ִ� ���ϱ�
    }
    sort(coord_plus_max, coord_plus_max + N);                                                                //x+y�� �ִ񰪰� �ּڰ� ������ ���� ����
    sort(coord_minus_max, coord_minus_max + N);                                                              //x-y�� �ִ񰪰� �ּڰ� ������ ���� ����
    L1_metric = max(coord_plus_max[N - 1] - coord_plus_max[0], coord_minus_max[N - 1] - coord_minus_max[0]); //������ �迭���� �ִ� �Ǻ�
    free(coord_plus_max);
    free(coord_minus_max);
    cout << L1_metric;
    return 0;
}