/*
递增子序列
https://leetcode.cn/problems/non-decreasing-subsequences/
第一次自己独立按照二叉树，实现回溯。中途出现了很多问题并进行对照修改
注意：本题不能对原数组进行排序，否则排完序的数组自身就是自增子序列。
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startindex)
    {
        //这里并不会结束程序，每个节点如果满足条件就会保存起来，之后该组合还可以继续向后延伸递归
        if (path.size() > 1)
        {
            result.push_back(path);
        }
        unordered_set<int> used;
        //no end condition, startindex will solve this
        for (int i = startindex; i < nums.size(); i++)
        {
            //两个部分需要去重
            //同一父节点下重复、不满足递增子序列
            if ((!path.empty() && nums[i] < path.back()) || used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
