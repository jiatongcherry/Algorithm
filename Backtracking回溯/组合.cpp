//组合：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
//https://leetcode.cn/problems/combinations/description/

/*
解释：这里设置的cur_index，是由于两个值是从同一个集合中取得，为了避免重复数据，所以设置cur_index,取大于i的数值
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int cur_index)
    {
        //end
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        //digui
        for (int i = cur_index; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};


//组合总和：找出所有相加之和为 n 的 k 个数的组合
//https://leetcode.cn/problems/combination-sum-iii/
/*
解释：基本思路都和上面相似，但是对于满足相加之和的判断，加在递归结束的部分
满足递归结束的条件时，如果满足条件就添加。之后统一都需要return
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int cur_index, int sum)
    {
        //end
        if (path.size() == k)
        {
            if (sum == n) result.push_back(path);
            return;
        }
        //digui
        for (int i = cur_index; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return result;
    }
};
//剪枝version
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int cur_index, int sum)
    {
        //end
        if (sum > n) return; //剪枝条件
        if (path.size() == k)
        {
            if (sum == n) result.push_back(path);
            return;
        }
        //digui
        for (int i = cur_index; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return result;
    }
};