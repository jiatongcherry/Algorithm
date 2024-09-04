/*
摆动序列 贪心算法/动态规划
https://leetcode.cn/problems/wiggle-subsequence/description/
*/

//同时将只有两个元素的情况考虑进去 - 将其扩展为三个元素
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//仍有部分案例无法通过，见情况三
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int prediff = 0;
        int backdiff = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            backdiff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && backdiff > 0) || (prediff >= 0 && backdiff < 0)) result += 1;
            prediff = backdiff;
        }
        return result;
    }
};

//情况三：单调坡度有平坡
//由于对prediff的更新不正确导致
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int prediff = 0;
        int backdiff = 0;
        int result = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            backdiff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && backdiff > 0) || (prediff >= 0 && backdiff < 0))
            {
                result += 1;
                prediff = backdiff;
            }
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> vec2 = { 1, 7,4,9,2,5 };
    cout << solution.wiggleMaxLength(vec2) << endl;
}
