/*
面试题 04.02. 最小高度树
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 
	 
来源：LeetCode
链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci/
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
    TreeNode* _sortedArrayToBST(vector<int>& nums, int begin, int end)
    {
        if(begin >= end)
            return nullptr;
        
        int mid = begin + (end - begin) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(nums, begin, mid);
        root->right = _sortedArrayToBST(nums, mid + 1, end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }
};