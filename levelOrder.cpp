/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nq;
        queue<int> lq;
        vector<vector<int>> vv;
        
        if(root != nullptr)
        {
            nq.push(root);
            lq.push(0);
        }
        
        int curl = - 1;
        
        while(!nq.empty())
        {
            TreeNode* node = nq.front();
            nq.pop();
            int level = lq.front();
            lq.pop();
            
            if(level > curl)
            {
                vv.push_back(vector<int>());
                curl = level;
            }
            
            vv[level].push_back(node->val);
            
            if(node->left)
            {
                nq.push(node->left);
                lq.push(level + 1);
            }
            if(node->right)
            {
                nq.push(node->right);
                lq.push(level + 1);
            }
        }
        
        return vv;
    }
};
