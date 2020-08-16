/*给定两个非空二叉树 s 和 t，
检验 s 中是否包含和 t 具有相同
结构和节点值的子树。s 的一个子
树包括 s 的一个节点和这个节点
的所有子孙。s 也可以看做它自身
的一棵子树*/
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
    bool _isSubStructure(TreeNode* A, TreeNode* B)
    {
        if(B == nullptr)
            return true;
        if(A == nullptr)
            return false;
        
        if(A->val != B->val)
            return false;
        
        return _isSubStructure(A->left, B->left) && _isSubStructure(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == nullptr || A == nullptr)
            return false;
        
        if(A->val == B->val)
            if(_isSubStructure(A, B))
                return true;
        
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
};