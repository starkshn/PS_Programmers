#include <string>
#include <vector>
using namespace std;


// 250321 
// ùǮ��
// �ִ� ���� 100�� ���� fIdx�� 105�� ���� 100 * 100 * 100�̶� ������ ���� ���̶� �Ǵ�
// fidx�� keymap���� ���� ����� �ε����� ���Ѵ�.
// ��� keymap���� ��ȸ�ϸ鼭 ���� ã�� ���� �ܾ �ִ��� Ȯ���ϴ� �ڵ�. 
 
vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;

    for (string str : targets)
    {
        int cnt = 0, fIdx = 105, ret = 0;
        while (1)
        {
            if (cnt == str.size()) break;
            for (string key : keymap)
            {
                for (int i = 0; i < key.size(); ++i)
                {
                    if (key[i] == str[cnt])
                    {
                        fIdx = min(fIdx, i + 1);
                    }
                }
            }
            if (fIdx == 105)
            {
                answer.push_back(-1);
                break;
            }
            else
            {
                cnt++;
                ret += fIdx;
                fIdx = 105;
            }
        }
        if (cnt == str.size()) answer.push_back(ret);
    }

    return answer;
}


// �ι�° Ǯ��
// map�� ���

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;
    map<char, int> m;
    for (int i = 0; i < keymap.size(); ++i)
    {
        for (int j = 0; j < keymap[i].size(); ++j)
        {
            if (m.find(keymap[i][j]) == m.end())
                m.insert(pair<char, int>(keymap[i][j], j + 1));
            else
            {
                if (m[keymap[i][j]] > j + 1)
                    m[keymap[i][j]] = j + 1;
            }       
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < targets.size(); ++i)
    {
        cnt = 0;
        for (int j = 0; j < targets[i].size(); ++j)
        {
            if (m.find(targets[i][j]) == m.end())
            {
                cnt = -1;
                break;
            }
            auto tmp = targets[i][j];
            cnt += m[tmp];
        }
        answer.push_back(cnt);
    }
    
    return answer;
} 
