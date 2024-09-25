/*
��ȫ�������Ľڵ����
https://leetcode.cn/problems/count-complete-tree-nodes/description/
���ֽⷨ��ע���ע���������ĵݹ�ⷨ
*/

//��ͨ���������
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

//��ȫ�������ⷨ
//��Ҫ�����ȫ�������Ķ���
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
            //ע�⣺��ʾָ������ʹ��λ��
            return (2 << leftlength) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};