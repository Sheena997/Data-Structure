/*
111. ����������С���
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:
���������� [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
����������С���  2.

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int leftLen = minDepth(root->left);
        int rightLen = minDepth(root->right);
        
        if(leftLen != 0 && rightLen != 0)
            return 1 + min(leftLen, rightLen);
        else
            return 1 + leftLen + rightLen;
    }
};