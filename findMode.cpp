/*
501. �����������е�����
����һ������ֵͬ�Ķ�����������BST�����ҳ� BST �е���������������Ƶ����ߵ�Ԫ�أ���
�ٶ� BST �����¶��壺
�������������������ֵС�ڵ��ڵ�ǰ����ֵ
�������������������ֵ���ڵ��ڵ�ǰ����ֵ
�����������������Ƕ���������
���磺
���� BST [1,null,2,2],

   1
    \
     2
    /
   2
����[2].
��ʾ�������������1�������迼�����˳��
���ף�����Բ�ʹ�ö���Ŀռ��𣿣������ɵݹ��������ʽ����ջ�Ŀ��������������ڣ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
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
    map<int, int> mp;
    
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);
        ++mp[root->val];
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        
        inorder(root);
        int most = INT_MIN;
        auto it = mp.begin();
        for(; it != mp.end(); ++it)
        {
            if(it->second > most)
                most = it->second;
        }
        for(it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->second == most)
                res.push_back(it->first);
        }
            
        return res;
    } 
};