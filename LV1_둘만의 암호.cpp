#include <string>
#include <vector>

using namespace std;

// 250326
// skip문자열 자체를 정렬하려 했지만 string::find함수를 통해 찾기만 하면 문제가 없을 것이라 판단해서 정렬하지 않음
// cnt = 0으로 두고 index보다 작을 때까지 계속 돌린다. 

string solution(string s, string skip, int index) 
{
    string answer = "";
    for (char c : s)
    {
        int cnt = 0;
        while (cnt < index)
        {
            c++;
            if (c > 'z') c = 'a';
            if (skip.find(c) == string::npos)
                ++cnt;
        }
        answer += c;
    }
    return answer;
}



// IsSkip함수를 만들어서 스킵해야한다면 스킵하는 식의 로직 

#include <string>
#include <vector>

using namespace std;

bool IsSkip(char c, const string& str)
{
    for (int i = 0; i < str.size(); ++i)
        if (c == str[i]) return true;
    return false;
}

string solution(string s, string skip, int index) 
{
    string answer = "";
    for (char c : s)
    {
        for (int i = 0; i < index;)
        {
            c += 1;
            if (c == 'z' + 1) c = 'a';
            if (!IsSkip(c, skip))
                ++i;
        }
        answer.push_back(c);
    }
    return answer;
}
