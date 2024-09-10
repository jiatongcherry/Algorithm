/*
对称二叉树
https://leetcode.cn/problems/symmetric-tree/
本身计划使用队列，但其实这种比较很难对单个节点操作和移除
采用递归的思想，刚好是一层一层对子树进行检验的
之后也可以采用队列或栈，但是需要两个两个节点进行操作
*/
class Solution {
public:
    bool judge(TreeNode* left, TreeNode* right)
    {
        //终止条件
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL & right == NULL) return true;
        else if (left->val != right->val) return false;

        //递归：如果值相等，需要再检查子节点
        //注意：需要判断两侧、中间
        int outer = judge(left->left, right->right);
        int inner = judge(left->right, right->left);
        return outer && inner;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return judge(root->left, root->right);
    }
};