//baekjoon 2609  최대공약수와 최소공배수
#include <iostream>
using namespace std;
int main(void)
{
    int a, b, gcd, lcm, i = 1;
    cin >> a >> b;
    if (a > b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    while (i <= a)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
        i++;
    }
    lcm = (a * b) / gcd;
    cout << gcd << "\n"
         << lcm;
    return 0;
}