/*
K 次取反后最大化的数组和  https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
第二步：从前向后遍历，遇到负数将其变为正数，同时K--
第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
第四步：求和
*/
class Solution {
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //step1
        sort(nums.begin(), nums.end(), cmp);

        //step2 abs较大的数在数组最后，从最后开始遍历，变abs较大的数的符号
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        //step3 注意这里替换循环复杂的表达，只需要一直循环改变abs最小的那个数的符号即可，但是由于改变两次会回到原先的值，所以只需要判断奇偶性
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;

        //step4
        int result = 0;
        for (int num : nums) result += num;

        return result;
    }
};