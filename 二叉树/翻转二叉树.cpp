//递归法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //使用前序遍历
        if (root == NULL) return root;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

//迭代法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> result;
        result.push(root);

        while (!result.empty())
        {
            TreeNode* node = result.top();
            result.pop();
            swap(node->left, node->right);

            if (node->right) result.push(node->right);
            if (node->left) result.push(node->left);

        }
        return root;
    }
};