/*
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
示例 1:
输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
*/
//数据结构
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int i = 0, n = q.size();
            double sum = 0;
            while(i < n)
            {
                TreeNode* v = q.front();
                sum += v->val;
                q.pop();
                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
                ++i;
            }
            res.push_back(sum / n);
        }
        
        return res;
    }
};
