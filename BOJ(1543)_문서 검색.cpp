//baekjoon 1543 ���� �˻�
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s;
    string word;
    int cnt = 0, s_len, word_len, j = 0, k;

    getline(cin, s);
    getline(cin, word);
    s_len = s.size();
    word_len = word.size();
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == word[j])
        {
            k = i;
            for (j = 0; j < word_len; j++)
            {
                if (s[i] != word[j])
                    break;
                i++;
            }
            if (j == word_len)
                cnt++;
            else
                i = k + 1; //break ������ ��� i ������° index���� �ٽ� Ž��
            j = 0;
            i--;
        }
    }
    cout << cnt;
    return 0;
}