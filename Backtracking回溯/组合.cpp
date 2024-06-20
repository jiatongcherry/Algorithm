//��ϣ������������� n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
//https://leetcode.cn/problems/combinations/description/

/*
���ͣ��������õ�cur_index������������ֵ�Ǵ�ͬһ��������ȡ�ã�Ϊ�˱����ظ����ݣ���������cur_index,ȡ����i����ֵ
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


//����ܺͣ��ҳ��������֮��Ϊ n �� k ���������
//https://leetcode.cn/problems/combination-sum-iii/
/*
���ͣ�����˼·�����������ƣ����Ƕ����������֮�͵��жϣ����ڵݹ�����Ĳ���
����ݹ����������ʱ�����������������ӡ�֮��ͳһ����Ҫreturn
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
//��֦version
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int cur_index, int sum)
    {
        //end
        if (sum > n) return; //��֦����
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