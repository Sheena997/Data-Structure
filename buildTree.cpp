/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//加了map之后不需每次都遍历一遍，而是二分查找，以空间换时间
class Solution {
public:
    map<int, int> mp;
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int inbegin, int inend)
    {
        if(inbegin > inend)
            return nullptr;
        
        int rootVal = preorder[prei];
        TreeNode* root = new TreeNode(rootVal);
        
        //在中序中找根位置
        /*
        int inRoot = inbegin;
        while(inRoot <= inend)
        {
            if(inorder[inRoot] == rootVal)
                break;
            ++inRoot;
        }
        */
        int inRoot = mp[rootVal];
        
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
        for(int i = 0; i < inorder.size(); ++i)
            mp.insert(pair<int, int>(inorder[i], i));
    
        
        int prei = 0, inbegin = 0, inend = inorder.size() - 1;
        
        return _buildTree(preorder, inorder, prei, inbegin, inend); 
    }
};
