/*
����������
https://leetcode.cn/problems/non-decreasing-subsequences/
��һ���Լ��������ն�������ʵ�ֻ��ݡ���;�����˺ܶ����Ⲣ���ж����޸�
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startindex)
    {
        //���ﲢ�����������ÿ���ڵ�������������ͻᱣ��������֮�����ϻ����Լ����������ݹ�
        if (path.size() > 1)
        {
            result.push_back(path);
        }
        unordered_set<int> used;
        //no end condition, startindex will solve this
        for (int i = startindex; i < nums.size(); i++)
        {
            //����������Ҫȥ��
            //ͬһ���ڵ����ظ������������������
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