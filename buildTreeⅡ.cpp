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
//加了map不再每次都要遍历，而是每次二分遍历，以空间换时间

class Solution {
public:
    map<int, int> mp;
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posti, int inbegin, int inend)
    {
        if(inbegin > inend)
            return nullptr;
        
        int rootVal = postorder[posti]; 
        TreeNode* root = new TreeNode(rootVal);
        
        /*
        int rooti = inbegin;
        while(rooti <= inend)
        {
            if(rootVal == inorder[rooti])
                break;
            ++rooti;
        }
        */
        int rooti = mp[rootVal];
        
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
        for(int i = 0; i < inorder.size(); ++i)
            mp.insert(pair<int, int>(inorder[i], i));
        
        int posti = postorder.size() - 1, inbegin = 0, inend = inorder.size() - 1;
        
        return _buildTree(inorder, postorder, posti, inbegin, inend);
    }
};
