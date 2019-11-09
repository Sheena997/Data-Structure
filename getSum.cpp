/*
从根到叶的二进制数之和
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
以 10^9 + 7 为模，返回这些数字之和。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers
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
    int getSum(TreeNode* node, int val)
    {
        if(node == NULL)
            return 0;
        int sum = val << 1 | node->val;
        if(node->left == NULL && node->right == NULL)
            return sum;
        return getSum(node->left, sum) + getSum(node->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return getSum(root, 0);
    }
};
