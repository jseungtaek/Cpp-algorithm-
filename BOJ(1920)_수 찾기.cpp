//baekjoon 1920 수 찾기
#include <iostream>
#include <stdio.h>
//#include <vector>
#include <stdlib.h>
#define MAX 100001
//#include <algorithm> quick sort

using namespace std;

int arr_copy[MAX];
int N, M;
int *arr;

void merge(int *arr, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            arr_copy[k] = arr[i];
            i++;
        }
        else //arr[i] > arr[j]
        {
            arr_copy[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        for (int m = j; m <= end; m++)
        {
            arr_copy[k] = arr[m];
            k++;
        }
    }
    else
    {
        for (int m = i; m <= mid; m++)
        {
            arr_copy[k] = arr[m];
            k++;
        }
    }

    //sort arr insert
    for (int m = start; m <= end; m++)
        arr[m] = arr_copy[m];
}

void merge_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);   //좌측정렬
        merge_sort(arr, mid + 1, end); //우측정렬
        merge(arr, start, mid, end);
    }
}

void binary_search(int *arr, int num)
{
    int left = 0;
    int right = N - 1;
    while (left <= right) //binary search
    {
        int mid = (left + right) / 2;
        if (arr[mid] == num)
        {
            printf("1\n");
            return;
        }
        else if (arr[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("0\n");
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // cin speed up
    //vector<int> arr;
    //vector<int> num;
    //int *num;
    int x;

    cin >> N;
    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    //sort(arr.begin(), arr.end());
    merge_sort(arr, 0, N - 1);
    cin >> M;
    //num = (int *)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
    {
        /*left = arr[0];
		right = arr[N - 1];*/
        //cin >> num[i];
        cin >> x;
        binary_search(arr, x);
    }
    return 0;
}
