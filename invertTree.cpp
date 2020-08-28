/*
226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是
您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。

来源：LeetCode
链接：https://leetcode-cn.com/problems/invert-binary-tree/
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* cur = new TreeNode(root->val);
        
        cur->left = invertTree(root->right);
        cur->right = invertTree(root->left);
        
        return cur;
    }
};