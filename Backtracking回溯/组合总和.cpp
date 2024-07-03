//组合总和：给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的数字可以无限制重复被选取。
//https://leetcode.cn/problems/combination-sum/

/*
1. 递归return条件：没有遍历次数的限制，满足总和条件即可返回
2. startIndex：避免重复的参数 在同一集合里选需要加startindex，不在同一集合选不用该参数
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if (sum > target) return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};


// 组合总和II：给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中只能使用一次。
//https://leetcode.cn/problems/combination-sum-ii/

/*
1. 递归return条件：没有遍历次数的限制，满足总和条件即可返回
2. startIndex：避免重复的参数 在同一集合里选需要加startindex，不在同一集合选不用该参数
*/

// 组合总和II：给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。candidates 中的每个数字在每个组合中只能使用一次。
//https://leetcode.cn/problems/combination-sum-ii/

/*
去重：解集不能包含重复的组合 —— 同一树层去重 使用used数组
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int target, int sum, int startindex, vector<bool> used)
    {
        //end
        if (sum > target) return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = startindex; i < candidates.size(); i++)
        {
            //同层去重
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

            sum += candidates[i];
            used[i] = true;
            path.push_back(candidates[i]);

            backtracking(candidates, target, sum, i + 1, used);  //i+1:candidates中的每个数字在每个组合中只能使用 一次

            sum -= candidates[i];
            used[i] = false;
            path.pop_back();


        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
