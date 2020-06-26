/*
剑指 Offer 34. 二叉树中和为某一值的路径
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

 

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
 

提示：

节点总数 <= 10000
来源：leetcode
链接https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
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
    void _pathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& ret, int count)
    {
        if(root == NULL)
            return;
        count += root->val;
        ret.push_back(root->val);
        if(root->left == NULL && root->right == NULL && count == sum)
            res.push_back(ret);
            
        

        _pathSum(root->left, sum, res, ret, count);
        _pathSum(root->right, sum, res, ret, count);
        ret.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> ret;
        int count = 0;
        
        _pathSum(root, sum, res, ret, count);
        
        return res;
    }
};