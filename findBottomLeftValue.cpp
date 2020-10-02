/*
513. 找树左下角的值
给定一个二叉树，在树的最后一行找到最左边的值。
示例 1:
输入:

    2
   / \
  1   3

输出:
1
 

示例 2:
输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 
注意: 您可以假设树（即给定的根节点）不为 NULL。

来源：LeetCode
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value/
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