/*
226. ��ת������
��תһ�ö�������

ʾ����

���룺

     4
   /   \
  2     7
 / \   / \
1   3 6   9
�����

     4
   /   \
  7     2
 / \   / \
9   6 3   1
��ע:
����������ܵ� Max Howell �� ԭ���� ������ ��

�ȸ裺����90���Ĺ���ʦʹ������д�����(Homebrew)������
��ȴ�޷�������ʱ�ڰװ���д����ת����������⣬��̫����ˡ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/invert-binary-tree/
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