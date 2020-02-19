/*
530. 二叉搜索树的最小绝对差
给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
示例 :
输入:
   1
    \
     3
    /
   2
输出:
1
解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
注意: 树中至少有2个节点。
*/
// BST性质，中序遍历得到的一定是一个非降序数列
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