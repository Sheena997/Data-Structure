/*
��ָ Offer 34. �������к�Ϊĳһֵ��·��
����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·����
�����ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����

 

ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
����:

[
   [5,4,11,2],
   [5,8,4,5]
]
 

��ʾ��

�ڵ����� <= 10000
��Դ��leetcode
����https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
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