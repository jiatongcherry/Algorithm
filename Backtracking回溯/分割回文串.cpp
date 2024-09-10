//�ָ���Ĵ�
//https://leetcode.cn/problems/palindrome-partitioning/

//������⣬��Ӷ��ַ����и�Ĳ���

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;

    void backtracking(const string& s, int startindex)
    {
        //Ҷ�ӽڵ�
        if (startindex >= s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = startindex; i < s.size(); i++)
        {
            if (isPalindrome(s, startindex, i)) //����startindex��i����ѡ�����Ӵ���������Ҫ���и���Ӵ�
            {
                string sub_str = s.substr(startindex, i - startindex + 1);
                path.push_back(sub_str);
            }
            else continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};