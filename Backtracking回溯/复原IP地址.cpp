/*
复原IP地址
https://leetcode.cn/problems/restore-ip-addresses/
需要注意：剪枝策略以及子网是否合法的判断函数
*/

class Solution {
private:
    vector<string> result;

    void backtracking(string& s, int startindex, int pointnum)
    {
        //单次递归结束
        if (pointnum == 3)
        {
            if (judge(s, startindex, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }

        //同一树枝循环
        for (int i = startindex; i < s.size(); i++)
        {
            if (judge(s, startindex, i)) //if it is valid, insert . into s
            {
                s.insert(s.begin() + i + 1, '.');
                pointnum++;
                backtracking(s, i + 2, pointnum);
                //backtracking
                pointnum--;
                s.erase(s.begin() + i + 1);
            }
            else continue;
        }
    }

    bool judge(const string& s, int start, int end)
    {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;

        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255) return false;
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};