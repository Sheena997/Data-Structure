/*
106. �����������������й��������
����һ��������������������������������

ע��:
����Լ�������û���ظ���Ԫ�ء�

���磬����

������� inorder = [9,3,15,20,7]
������� postorder = [9,15,7,20,3]
�������µĶ�������

    3
   / \
  9  20
    /  \
   15   7
   
��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
 
 //����������Ǳ������������ĸ��������Ƚ��������ٽ�������
class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posti, int inbegin, int inend)
    {
        if(inbegin > inend)
            return nullptr;
        
        int rootVal = postorder[posti]; 
        TreeNode* root = new TreeNode(rootVal);
        
        int rooti = inbegin;
        while(rooti <= inend)
        {
            if(rootVal == inorder[rooti])
                break;
            ++rooti;
        }
        
        
        if(rooti + 1 <= inend)
            root -> right = _buildTree(inorder, postorder, --posti, rooti + 1, inend);
        else 
            root -> right = nullptr;
        if(inbegin <= rooti - 1)
            root -> left = _buildTree(inorder, postorder, --posti, inbegin, rooti - 1);
        else
            root -> left = nullptr;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posti = postorder.size() - 1, inbegin = 0, inend = inorder.size() - 1;
        
        return _buildTree(inorder, postorder, posti, inbegin, inend);
    }
};