//baekjoon 1300 K번째 수
#include <iostream>
#include <algorithm>
//이분탐색 알고리즘 적용
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
            cnt += min(mid / i, N); //mid/i 값이 해당 행에서 mid보다 작은 값임을 알 수 있다. 따라서 행에서 mid보다 작거나 같은 숫자는 min(mid / i , N)으로 구할 수 있음
        }
        if (cnt >= k) //mid보다 작거나 같은 수가 k값 보다 크거나 같으면 result = mid, finish를 mid + 1
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