/*
530. ��������������С���Բ�
����һ�����нڵ�Ϊ�Ǹ�ֵ�Ķ������������������������ڵ�Ĳ�ľ���ֵ����Сֵ��
ʾ�� :
����:
   1
    \
     3
    /
   2
���:
1
����:
��С���Բ�Ϊ1������ 2 �� 1 �Ĳ�ľ���ֵΪ 1������ 2 �� 3����
ע��: ����������2���ڵ㡣
*/
// BST���ʣ���������õ���һ����һ���ǽ�������
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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre = INT_MAX;
        getMinimum(root, res, pre);
        return res;
    }
    void getMinimum(TreeNode* root, int& res, int& pre)
    {
        if(root == NULL)
            return;
        getMinimum(root -> left, res, pre);
        int tmp = abs(pre - root -> val);
        if(tmp < res)
            res = tmp;
        pre = root -> val;
        getMinimum(root -> right, res, pre);
        
        return;
    }
};