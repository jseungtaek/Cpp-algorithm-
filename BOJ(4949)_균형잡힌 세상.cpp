#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) 
{
	stack<char> data;
	string str;
	int i,flag;
	
	while(1)
	{
		getline(cin, str);
		if (str==".")
		{
			break;
		}
		i = 0;
		flag = 0;
		while(str[i])
		{
			if (str[i] == '(' || str[i] == '[')
			{
				data.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if(data.top() == '(')
				{
					data.pop();
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else if (str[i] == ']')
			{
				if(data.top() == '[')
				{
					data.pop();
				}
				else
				{
					flag = 1;
					break;
				}
			}
			i++;
		}
		if (flag && !data.empty())
		{
			cout << "no\n";
		}
		else
		{
			cout << "yes\n";
		}
	}
	return 0;
}
