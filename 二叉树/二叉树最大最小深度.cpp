/*
二叉树最大深度 https://leetcode.cn/problems/maximum-depth-of-binary-tree/
二叉树最小深度 https://leetcode.cn/problems/minimum-depth-of-binary-tree/
也可以使用迭代法层序遍历，只需要在每次统计size时让depth++即可
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//最大深度
class Solution {
public:
    int getdepth(TreeNode* node)
    {
        //递归
        //深度遍历 后序遍历
        if (node == NULL) return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        int depth = max(leftdepth, rightdepth) + 1; //加root的深度1
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};

class Solution {
public:
    int result = 0;
    void getdepth(TreeNode* node, int depth)
    {
        //递归
        //深度遍历 前序遍历 需要回溯
        result = max(depth, result);

        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL) return;
        if (node->left)
        {
            depth++;
            getdepth(node->left, depth);
            depth--;
        }
        if (node->right)
        {
            depth++;
            getdepth(node->right, depth);
            depth--;
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        getdepth(root, 1);
        return result;
    }
};

//最小深度 后序遍历
 //注意叶子节点，左右孩子都为NULL
class Solution {
public:
    int getdepth(TreeNode* node)
    {
        if(node == NULL) return 0;
       
        int lefftdepth = getdepth(node->left);
        int righttdepth = getdepth(node->right);
        if(node->left==NULL && node->right!=NULL) return righttdepth+1;
        if(node->left!=NULL && node->right==NULL) return lefftdepth+1;

        int depth = min(lefftdepth, righttdepth) + 1;
        return depth;
    }
    int minDepth(TreeNode* root) {
        return getdepth(root);
    }
};

//test set
int main()
{
    Solution solution;
    TreeNode* tree = new TreeNode(1);
    tree->right = new TreeNode(2);
    return solution.maxDepth(tree);
}
