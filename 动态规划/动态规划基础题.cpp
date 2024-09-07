/*
1.쳲��������� https://leetcode.cn/problems/fibonacci-number/
2.��¥�� https://leetcode.cn/problems/climbing-stairs/description/
3.ʹ����С������¥�� https://leetcode.cn/problems/min-cost-climbing-stairs/
*/


//쳲���������
class Solution {
public:
    int fib(int n) {
        if (n < 2) { return n; }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//��¥�� ����쳲���������
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n; // ��Ϊ����ֱ�Ӷ�dp[2]�����ˣ���ֹ��ָ��
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) { // ע��i�Ǵ�3��ʼ��
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//ʹ����С������¥��
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));

        }
        return dp[cost.size()];
    }
};