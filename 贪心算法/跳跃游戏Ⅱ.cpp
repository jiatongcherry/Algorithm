//跳跃游戏 II
//https://leetcode.cn/problems/jump-game-ii/
//这时候需要两个cover来选择，如果走到该步最大可以cover的位置，之前所有node的cover都到不了终点，那么才需要移动一步
//如果都到不了，贪心的下一步就选择能够到达的最远位置
class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int curCover = 0;
        int nextCover = 0;
        if (nums.size() == 1) return 0; //注意边界条件
        for (int i = 0; i < nums.size(); i++)
        {
            nextCover = max(nextCover, i + nums[i]);
            //初始情况也包括 同时如果走到当前可以走的最末尾
            if (i == curCover)
            {
                result++;
                curCover = nextCover;
            }
            if (curCover >= nums.size() - 1) break;
        }
        return result;
    }
};