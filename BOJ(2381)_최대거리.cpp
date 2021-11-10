//baekjoon 2381 최대거리
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
        coord_plus_max[i] = x + y;  //(x_1 + y_1) - (x_2 + y_2) 의 최댓값 구하기
        coord_minus_max[i] = x - y; //(x_1 - y_1) - (x_2 - y_2) 의 최댓값 구하기
    }
    sort(coord_plus_max, coord_plus_max + N);                                                                //x+y의 최댓값과 최솟값 구분을 위한 정렬
    sort(coord_minus_max, coord_minus_max + N);                                                              //x-y의 최댓값과 최솟값 구분을 위한 정렬
    L1_metric = max(coord_plus_max[N - 1] - coord_plus_max[0], coord_minus_max[N - 1] - coord_minus_max[0]); //정렬한 배열에서 최댓값 판별
    free(coord_plus_max);
    free(coord_minus_max);
    cout << L1_metric;
    return 0;
}