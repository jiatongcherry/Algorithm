//卖卖股票最佳时机
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//本题的关键是需要将一段很长的时间拆分为一个一个小段，直接采用贪心就可以解决
//否则需要写很多策略判断是否需要买进或者卖出

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int interest = 0;
        vector<int> gap(prices.size());
        for (int i = 1; i < prices.size(); i++)
        {
            gap[i - 1] = prices[i] - prices[i - 1];
            if (gap[i - 1] > 0) interest += gap[i - 1];
        }
        return interest;

    }
};