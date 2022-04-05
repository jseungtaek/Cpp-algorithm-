// BOJ 2108 통계학
#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n, *num_array, cnt_array[8002], max = INT_MIN, min = INT_MAX, cnt = 0, cnt_num, count = 0;
    double sum = 0;

    cin >> n;
    num_array = new int[n];

    for (int i = 0; i <= 8000; i++)
        cnt_array[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum += (double)num;
        num_array[i] = num;
        if (num < 0)
        {
            int _num = abs(num);
            cnt_array[4000 + _num]++;
            if (cnt_array[4000 + _num] > cnt)
            {
                cnt = cnt_array[4000 + _num];
                cnt_num = 4000 + _num;
            }
        }
        else
        {
            cnt_array[num]++;
            if (cnt_array[num] > cnt)
            {
                cnt = cnt_array[num];
                cnt_num = num;
            }
        }
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    stable_sort(num_array, num_array + n);
    for (int i = 8000; i > 4000; i--)
    {
        if (cnt == cnt_array[i])
        {
            cnt_num = (i - 4000) * -1;
            count++;
        }
        if (count == 2)
            break;
    }
    if (count != 2)
    {
        for (int i = 0; i <= 4000; i++)
        {
            if (cnt == cnt_array[i])
            {
                cnt_num = i;
                count++;
            }
            if (count == 2)
                break;
        }
    }
    int _sum = round(sum/(double)(n));
    cout << _sum << endl
         << num_array[n / 2] << endl
         << cnt_num << endl
         << abs(max - min) << endl;

    delete [] num_array;
    return 0;
}