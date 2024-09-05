/*
������� ģ��
��: https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
��: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
ʹ�ö��� ����ס�ڵ㴦��ͽ����˳��
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);

        while (!que.empty())
        {
            int size = que.size(); //һ��Ҫʹ�ù̶���sizeֵ���������ѭ��
            vector<int> num;

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                num.push_back(node->val);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(num);
        }
        return result;
    }
};