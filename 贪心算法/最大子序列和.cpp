/*
最大子序列和
https://leetcode.cn/problems/maximum-subarray/description/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int sum = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            result = max(result, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return result;
    }
};