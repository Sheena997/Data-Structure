/*
1315. �游�ڵ�ֵΪż���Ľڵ��
����һ�ö����������㷵�������������������нڵ��ֵ֮�ͣ�
�ýڵ���游�ڵ��ֵΪż������һ���ڵ���游�ڵ���ָ�ýڵ�ĸ��ڵ�ĸ��ڵ㡣��
����������游�ڵ�ֵΪż���Ľڵ㣬��ô���� 0 ��
ʾ����
���룺root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
�����18
���ͣ�ͼ�к�ɫ�ڵ���游�ڵ��ֵΪż������ɫ�ڵ�Ϊ��Щ��ɫ�ڵ���游�ڵ㡣
��ʾ��
���нڵ����Ŀ�� 1 �� 10^4 ֮�䡣
ÿ���ڵ��ֵ�� 1 �� 100 ֮�䡣
ͨ������3,861�ύ����4,813

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int res = 0;
        if((root->val & 1) == 0)
        {
            if(root->right)
            {
                if(root->right->right)
                    res += root->right->right->val;
                if(root->right->left)
                    res += root->right->left->val;
            }
            if(root->left)
            {
                if(root->left->left)
                    res += root->left->left->val;
                if(root->left->right)
                    res += root->left->right->val;
            }
        }
        
        return res + sumEvenGrandparent(root->right) + sumEvenGrandparent(root->left);
    }
};