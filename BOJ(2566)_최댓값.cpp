#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    int max = INT_MIN;
    int x, y;
    
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            int num;
            cin >> num;
            if (num > max)
            {
                max = num;
                x = i + 1;
                y = j + 1;
            }
        }
    }
    cout << max << endl << x << " " << y;
    return 0;
}