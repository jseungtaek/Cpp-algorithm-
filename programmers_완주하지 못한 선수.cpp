#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    int len = participant.size(), i = 0;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (i = 0; i < len; i++)
    {
        if (participant[i] != completion[i])
            return participant[i];
    }
    return participant[i];
}

/*
string solution(vector<string> participant, vector<string> completion) {
    int len = participant.size(),i=0;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(i=0;i<len;i++)
    {
        if(participant[i] != completion[i])
        {
            string answer(participant[i]);
            return answer;
        }
    }
    string res(participant[i]);
    return res;
}
*/