#include <string>
#include <vector>

using namespace std;

// 250326
// skip���ڿ� ��ü�� �����Ϸ� ������ string::find�Լ��� ���� ã�⸸ �ϸ� ������ ���� ���̶� �Ǵ��ؼ� �������� ����
// cnt = 0���� �ΰ� index���� ���� ������ ��� ������. 

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



// IsSkip�Լ��� ���� ��ŵ�ؾ��Ѵٸ� ��ŵ�ϴ� ���� ���� 

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
