/*
计算给定二叉树的所有左叶子之和。
示例：
    3
   / \
  9  20
    /  \
   15   7
在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            sum += root->left->val;
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
