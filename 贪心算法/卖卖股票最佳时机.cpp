//������Ʊ���ʱ��
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//����Ĺؼ�����Ҫ��һ�κܳ���ʱ����Ϊһ��һ��С�Σ�ֱ�Ӳ���̰�ľͿ��Խ��
//������Ҫд�ܶ�����ж��Ƿ���Ҫ�����������

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