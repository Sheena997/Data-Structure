/*
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
示例 1:
输入: 
    2
   / \
  2   5
     / \
    5   7
输出: 5
说明: 最小的值是 2 ，第二小的值是 5 。
示例 2:
输入: 
    2
   / \
  2   2
输出: -1
说明: 最小的值是 2, 但是不存在第二小的值。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        prevOrderTraversal(root, s);
        if(s.size() <= 1)
            return -1;
        set<int>::iterator p = s.begin();
        ++p;
        return *p;
    }
    void prevOrderTraversal(TreeNode* root, set<int>& s)
    {
        if(root == NULL)
            return;
        s.insert(root->val);
        prevOrderTraversal(root->left, s);
        prevOrderTraversal(root->right, s);
    }
};