//baekjoon 13417 ī�� ���ڿ�
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
        card = (char *)malloc(sizeof(char) * N); //�����Ҵ�
        for (int j = 0; j < N; j++)
        {
            cin >> card[j];
            if (j == 0)
                deq.push_front(card[j]);     //ó������ ���ڴ� �ٷ� deq�� ����
            else if (deq.front() >= card[j]) //deq�� front�� ���� ascii ���� ���� ���ڸ� ����
                deq.push_front(card[j]);
            else // ������ deq.front ���� ���� ���̶�� push_back
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