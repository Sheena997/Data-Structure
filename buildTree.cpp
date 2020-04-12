/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：LeetCode
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
    {
        if(inbegin > inend)
            return nullptr;
        
        int rootVal = preorder[prei];
        TreeNode* root = new TreeNode(rootVal);
        
        //在中序中找根位置
        int inRoot = inbegin;
        while(inRoot <= inend)
        {
            if(inorder[inRoot] == rootVal)
                break;
            ++inRoot;
        }
        
		// [inbegin, inRooti-1] inRooti [inRooti+1, inend] 左子树的中序[inbegin, inRooti-1] 右子树的中序[inRooti+1, inend]
        // 如果中序左区间存在则递归创建左子树，如果中序左区间不存在，则左子树是空树
        if(inbegin <= inRoot - 1)
           root -> left =  _buildTree(preorder, inorder, ++prei, inbegin, inRoot - 1);
        else 
            root -> left = nullptr;
        if(inRoot + 1 <= inend)
            root -> right = _buildTree(preorder, inorder, ++prei, inRoot + 1, inend);
        else 
            root -> right = nullptr;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prei = 0, inbegin = 0, inend = inorder.size() - 1;
        
        return _buildTree(preorder, inorder, prei, inbegin, inend); 
    }
};