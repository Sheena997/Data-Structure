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
    vector<int> res;
    int ret = 0, count = 0;
    int pre = INT_MIN;
    
    void inorderVisit(TreeNode* root)
    {
        if(!root)
            return;
        inorderVisit(root->left);
        
        if(root->val == pre)
        {
            ++count;
        }
        else 
        {
            count = 1;
            pre = root->val;
        }
        
        if(count >= ret)
        {
            if(count > ret)
                res.clear();
            res.push_back(root->val);
            ret = count;
        }
            
        
        inorderVisit(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        inorderVisit(root);
        
        return res;
    }
};