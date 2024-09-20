/*
子集问题
https://leetcode.cn/problems/subsets/
*/

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