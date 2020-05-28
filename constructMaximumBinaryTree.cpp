/*
654. ��������
����һ�������ظ�Ԫ�ص��������顣һ���Դ����鹹�������������������£�
�������ĸ��������е����Ԫ�ء�
��������ͨ�����������ֵ��߲��ֹ����������������
��������ͨ�����������ֵ�ұ߲��ֹ����������������
ͨ�����������鹹�������������������������ĸ��ڵ㡣
ʾ�� ��
���룺[3,2,1,6,0,5]
�������������������ĸ��ڵ㣺

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 

��ʾ��
����������Ĵ�С�� [1, 1000] ֮�䡣

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/maximum-binary-tree/
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