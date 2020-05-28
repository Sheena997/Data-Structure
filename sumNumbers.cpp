/*
129. �����Ҷ�ӽڵ�����֮��
����һ��������������ÿ����㶼���һ�� 0-9 �����֣�
ÿ���Ӹ���Ҷ�ӽڵ��·��������һ�����֡�
���磬�Ӹ���Ҷ�ӽڵ�·�� 1->2->3 �������� 123��
����Ӹ���Ҷ�ӽڵ����ɵ���������֮�͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ�� 1:
����: [1,2,3]
    1
   / \
  2   3
���: 25
����:
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12.
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13.
��ˣ������ܺ� = 12 + 13 = 25.
ʾ�� 2:
����: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
���: 1026
����:
�Ӹ���Ҷ�ӽڵ�·�� 4->9->5 �������� 495.
�Ӹ���Ҷ�ӽڵ�·�� 4->9->1 �������� 491.
�Ӹ���Ҷ�ӽڵ�·�� 4->0 �������� 40.
��ˣ������ܺ� = 495 + 491 + 40 = 1026.

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
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
    int _sumNumber(TreeNode* root, int curSum)
    {
        if(!root)
            return 0;
        else if(!(root->left) && !(root->right))
            return 10 * curSum + root->val;
        
        return _sumNumber(root->left, 10 * curSum + root->val) + _sumNumber(root->right, 10 * curSum + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return _sumNumber(root, 0);
    }
};