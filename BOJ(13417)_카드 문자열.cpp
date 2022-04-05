//baekjoon 13417 카드 문자열
#include <iostream>
#include <deque>
#include <stdlib.h>
using namespace std;

int main(void)
{
    deque<char> deq;
    char *card;
    int T, N;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        card = (char *)malloc(sizeof(char) * N); //동적할당
        for (int j = 0; j < N; j++)
        {
            cin >> card[j];
            if (j == 0)
                deq.push_front(card[j]);     //처음들어온 문자는 바로 deq에 저장
            else if (deq.front() >= card[j]) //deq의 front에 가장 ascii 값이 낮은 문자를 저장
                deq.push_front(card[j]);
            else // 무조건 deq.front 보다 낮은 값이라면 push_back
                deq.push_back(card[j]);
        }
        while (!deq.empty())
        {
            cout << deq.front();
            deq.pop_front();
        }
        cout << "\n";
        free(card);
    }
    return 0;
}