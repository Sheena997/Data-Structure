/*
106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
   
来源：LeetCode
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
 
 //后序遍历先是遍历到右子树的根，所以先进右子树再进左子树
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