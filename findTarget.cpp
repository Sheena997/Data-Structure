/*
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
案例 1:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7
Target = 9
输出: True
案例 2:
输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
输出: False
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
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
    void inorder(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return ;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int left = 0, right = v.size() - 1;
        while(left < right)
        {
            int ret = v[left] + v[right];
            if(k == ret)
                return true;
            else if(k < ret)
                --right;
            else
                ++left;
        }
        return false;
    }
};