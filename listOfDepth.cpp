/*
面试题 04.03. 特定深度节点链表
给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表
（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含
所有深度的链表的数组。

示例：

输入：[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

输出：[[1],[2,3],[4,5,7],[8]]

来源：LeetCode
链接：https://leetcode-cn.com/problems/list-of-depth-lcci/
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> res;
        queue<TreeNode*> q;
        q.push(tree);
        while(!q.empty())
        {
            int size = q.size();
            ListNode* lst = nullptr;
            while(size--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(lst != nullptr)
                {
                    lst->next = new ListNode(cur->val);
                    lst = lst->next;
                }
                else
                {
                    lst = new ListNode(cur->val);
                    res.push_back(lst);
                }
                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
            }
        }
        
        return res;
    }
};