//����ܺͣ�����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�candidates �е����ֿ����������ظ���ѡȡ��
//https://leetcode.cn/problems/combination-sum/

/*
1. �ݹ�return������û�б������������ƣ������ܺ��������ɷ���
2. startIndex�������ظ��Ĳ��� ��ͬһ������ѡ��Ҫ��startindex������ͬһ����ѡ���øò���
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


// ����ܺ�II������һ������ candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
//https://leetcode.cn/problems/combination-sum-ii/

/*
1. �ݹ�return������û�б������������ƣ������ܺ��������ɷ���
2. startIndex�������ظ��Ĳ��� ��ͬһ������ѡ��Ҫ��startindex������ͬһ����ѡ���øò���
*/

// ����ܺ�II������һ������ candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
//https://leetcode.cn/problems/combination-sum-ii/

/*
ȥ�أ��⼯���ܰ����ظ������ ���� ͬһ����ȥ�� ʹ��used����
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
            //ͬ��ȥ��
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

            sum += candidates[i];
            used[i] = true;
            path.push_back(candidates[i]);

            backtracking(candidates, target, sum, i + 1, used);  //i+1:candidates�е�ÿ��������ÿ�������ֻ��ʹ�� һ��

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
