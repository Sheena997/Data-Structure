/*
������ 04.03. �ض���Ƚڵ�����
����һ�ö����������һ���㷨����������ĳһ��������нڵ������
�����磬��һ���������Ϊ D����ᴴ���� D ������������һ������
������ȵ���������顣

ʾ����

���룺[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

�����[[1],[2,3],[4,5,7],[8]]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/list-of-depth-lcci/
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