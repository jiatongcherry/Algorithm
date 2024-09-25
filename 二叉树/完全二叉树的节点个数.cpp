/*
完全二叉树的节点个数
https://leetcode.cn/problems/count-complete-tree-nodes/description/
两种解法，注意关注满二叉树的递归解法
*/

//普通二叉树解放
class Solution {
private:
    int count(TreeNode* node)
    {
        int nodenum = 0;
        if (node == NULL) return 0;
        int left = count(node->left);
        int right = count(node->right);
        return left + right + 1;
    }
public:
    int countNodes(TreeNode* root) {
        return count(root);
    }
};

//完全二叉树解法
//需要理解完全二叉树的定义
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftlength = 0, rightlength = 0;
        while (left)
        {
            left = left->left;
            leftlength++;
        }
        while (right)
        {
            right = right->right;
            rightlength++;
        }
        if (leftlength == rightlength)
        {
            //注意：表示指数运算使用位移
            return (2 << leftlength) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};