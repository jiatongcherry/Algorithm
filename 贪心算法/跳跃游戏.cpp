//跳跃游戏 https://leetcode.cn/problems/jump-game/
//怎么跳跃（每格跳多少步）不重要，重要的是跳跃覆盖范围
//将问题转化为范围是否可以覆盖最后一个点
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0; //最大可以覆盖到的下标
        for (int i = 0; i <= cover; i++) //注意cover是下标，所以可以取等
        {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};