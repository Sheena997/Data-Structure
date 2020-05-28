/*
654. 最大二叉树
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。
示例 ：
输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 

提示：
给定的数组的大小在 [1, 1000] 之间。

来源：LeetCode
链接：https://leetcode-cn.com/problems/maximum-binary-tree/
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
    void _constructMaximumBinaryTree(TreeNode*& root, int l, int r, vector<int>&nums)
    {
        if(l > r)
            return;
        
        int max = l;
        for(int i = l; i <= r; ++i)
        {
            if(nums[max] < nums[i])
                max = i;
        }
        
        root = new TreeNode(nums[max]);
        
        _constructMaximumBinaryTree(root->left, l, max - 1, nums);
        _constructMaximumBinaryTree(root->right, max + 1, r, nums);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root;
        
        _constructMaximumBinaryTree(root, 0, nums.size() - 1, nums);
        
        return root;
    }
};