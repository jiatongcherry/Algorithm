/*
1.斐波那契数列 https://leetcode.cn/problems/fibonacci-number/
2.爬楼梯 https://leetcode.cn/problems/climbing-stairs/description/
3.使用最小花费爬楼梯 https://leetcode.cn/problems/min-cost-climbing-stairs/
*/


//斐波那契数列
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

//爬楼梯 类似斐波那契数列
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n; // 因为下面直接对dp[2]操作了，防止空指针
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) { // 注意i是从3开始的
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//使用最小花费爬楼梯
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