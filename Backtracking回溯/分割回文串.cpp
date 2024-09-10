//分割回文串
//https://leetcode.cn/problems/palindrome-partitioning/

//组合问题，添加对字符串切割的操作

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;

    void backtracking(const string& s, int startindex)
    {
        //叶子节点
        if (startindex >= s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = startindex; i < s.size(); i++)
        {
            if (isPalindrome(s, startindex, i)) //根据startindex和i控制选区的子串，否则需要先切割出子串
            {
                string sub_str = s.substr(startindex, i - startindex + 1);
                path.push_back(sub_str);
            }
            else continue; //剪枝操作
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
