/*
513. �������½ǵ�ֵ
����һ�������������������һ���ҵ�����ߵ�ֵ��
ʾ�� 1:
����:

    2
   / \
  1   3

���:
1
 

ʾ�� 2:
����:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

���:
7
 
ע��: �����Լ��������������ĸ��ڵ㣩��Ϊ NULL��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return -1;
        
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);
        while(!q.empty())
        {
            node = q.front();
            q.pop();
            
            if(node->right)
                q.push(node->right);
            if(node->left)
                q.push(node->left);
        }
        
        return node->val;
    }
};