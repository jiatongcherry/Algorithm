/*
二叉树层平均值
https://leetcode.cn/problems/average-of-levels-in-binary-tree/
整体思路和二叉树层序遍历、二叉树右视图一致
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//二叉树层平均值
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty())
        {
            int num = que.size();
            double sum = 0;
            for (int i = 0; i < num; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(sum / num);
        }
        return result;
    }
};

//二叉树的右视图
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);

        while (!que.empty())
        {
            int size = que.size(); //一定要使用固定的size值控制下面的循环

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (i == (size - 1)) result.push_back(node->val);
            }
        }
        return result;
    }
};