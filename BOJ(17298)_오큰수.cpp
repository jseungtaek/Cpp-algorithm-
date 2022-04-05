//baekjoon 17298 오큰수
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
        while (!arr.empty() && arr.top() <= num[i]) //오큰수의 존재 유무 판별
        {
            arr.pop();
        }
        if (arr.empty()) //비어 있다면 배열의 해당 index는 오큰수가 존재하지 않음
            res[i] = -1;
        else //비어있지 않다면 오큰수가 존재하므로 stack에 쌓인 top index 값
            res[i] = arr.top();
        arr.push(num[i]); //stack에 쌓고 비교
    }
    for (i = 0; i < N; i++)
        cout << res[i] << " ";
    return 0;
}