//baekjoon 11004 K번째 수 merge sort
#include <iostream>
#include <stdlib.h>
using namespace std;

int *sorted;
int *A;
int N, K;

void merge(int *data, int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    int k = st;

    while (i <= mid && j <= end)
    {
        if (data[i] <= data[j])
        {
            sorted[k] = data[i];
            i++;
        }
        else
        {
            sorted[k] = data[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        for (int m = j; m <= end; m++)
        {
            sorted[k] = data[m];
            k++;
        }
    }
    else
    {
        for (int m = i; m <= mid; m++)
        {
            sorted[k] = data[m];
            k++;
        }
    }
    for (int m = st; m <= end; m++)
    {
        data[m] = sorted[m];
    }
}

void merge_sort(int *data, int st, int end)
{
    if (sorted == 0)
    {
        sorted = (int *)malloc(sizeof(int) * N + 1);
    }
    if (st < end)
    {
        int mid = (st + end) / 2;
        merge_sort(data, st, mid);
        merge_sort(data, mid + 1, end);
        merge(data, st, mid, end);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); //cin 속도 향상
    cin >> N >> K;
    A = (int *)malloc(sizeof(int) * N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    merge_sort(A, 1, N);
    cout << A[K];
    return 0;
}

//baekjoon 11004 K번째 수 (algorithm header 내장 sorted)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    vector<int> A;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int A_index;
        cin >> A_index;
        A.push_back(A_index);
    }
    sort(A.begin(), A.end());
    cout << A[K - 1];
    return 0;
}
