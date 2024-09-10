/*
�Գƶ�����
https://leetcode.cn/problems/symmetric-tree/
����ƻ�ʹ�ö��У�����ʵ���ֱȽϺ��ѶԵ����ڵ�������Ƴ�
���õݹ��˼�룬�պ���һ��һ����������м����
֮��Ҳ���Բ��ö��л�ջ��������Ҫ���������ڵ���в���
*/
class Solution {
public:
    bool judge(TreeNode* left, TreeNode* right)
    {
        //��ֹ����
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL & right == NULL) return true;
        else if (left->val != right->val) return false;

        //�ݹ飺���ֵ��ȣ���Ҫ�ټ���ӽڵ�
        //ע�⣺��Ҫ�ж����ࡢ�м�
        int outer = judge(left->left, right->right);
        int inner = judge(left->right, right->left);
        return outer && inner;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return judge(root->left, root->right);
    }
};