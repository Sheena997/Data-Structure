/*
������ 04.02. ��С�߶���
����һ�������������飬Ԫ�ظ�����ͬ�Ұ��������У���дһ���㷨������һ�ø߶���С�Ķ�����������

ʾ��:
������������: [-10,-3,0,5,9],

һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 
	 
��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/minimum-height-tree-lcci/
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