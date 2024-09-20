/*
�Ӽ������ & ��
https://leetcode.cn/problems/subsets/
https://leetcode.cn/problems/subsets-ii/
*/

//��
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtracking(vector<int>& nums, int startindex)
    {
        result.push_back(path);
        if (startindex == nums.size())
        {
            return;
        }

        for (int i = startindex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};

//�� ʹ��used���飬�ǵó�ʼ�������������
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used, int startindex)
    {
        result.push_back(path);
        if (startindex == nums.size()) return;

        for (int i = startindex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used, i + 1);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.begin() + nums.size());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, 0);
        return result;
    }
};