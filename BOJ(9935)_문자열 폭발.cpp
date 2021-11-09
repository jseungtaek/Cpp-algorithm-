//baekjoon 9935 문자열 폭발
/*#include <iostream>
#include <string>
#include <stack>
#include <string.h>
#define MAX 1000002
#define bomb 38
using namespace std;

int main(void)
{
	char str[MAX];
	char bomb_str[bomb];
	stack<char> res;
	char ans[MAX];
	int str_len, bomb_len, i, j, k, m, n, cnt = 0;

	cin >> str >> bomb_str;
	str_len = strlen(str);
	bomb_len = strlen(bomb_str);

	for (i = 0; str[i]; i++)
	{
		res.push(str[i]);

		if (res.top() == bomb_str[bomb_len - 1])
		{
			int flag = 0;
			n = bomb_len - 1;
			for (j = i - 1; j > i - bomb_len; j--)
			{
				res.pop();
				if (res.top() != bomb_str[--n])
				{
					flag = j;
					break;
				}
			}
			if (!flag)
			{
				for (k = flag; k <= i; k++)
					res.push(str[k]);
			}
			else
			{
				cnt++;
				for (m = j; m < str_len - (bomb_len * cnt); m++)
				{
					str[m] = str[m + bomb_len];
				}
			}
		}
	}
	if (!res.empty())
		cout << "FRULA";
	else
	{
		i = 0;
		while (!res.empty())
		{
			ans[i++] = res.top();
			res.pop();
		}
		ans[i] = 0;
		cout << ans;
	}
	return 0;
}*/
// 윗 방법은 stack overflow 공부 후 재시도
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	string bomb_str;
	string answer = "";
	int str_len, bomb_len;

	cin >> str >> bomb_str;

	str_len = str.length();
	bomb_len = bomb_str.length();

	for (int i = 0; i < str_len; i++)
	{
		answer += str[i]; //string에 한 문자씩 추가

		if (str[i] == bomb_str[bomb_len - 1])
		{
			if (answer.size() >= bomb_len)
			{
				int cnt = 0;
				int n = answer.size();
				for (int j = bomb_len - 1; j >= 0; j--) //문자열을 거꾸로 비교
				{
					if (answer[n - (bomb_len - 1 - j) - 1] == bomb_str[j])
						cnt++;
				}
				if (cnt == bomb_len) //bomb 문자열과 비교한 값이 bomb의 길이와 같으면 pop
				{
					for (int j = 0; j < bomb_len; j++)
						answer.pop_back();
				}
			}
		}
	}
	if (!answer.empty())
		cout << answer;
	else
		cout << "FRULA";
	return 0;
}