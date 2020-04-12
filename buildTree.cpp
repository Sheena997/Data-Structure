/*
105. ��ǰ��������������й��������
����һ������ǰ�������������������������
ע��:
����Լ�������û���ظ���Ԫ�ء�
���磬����
ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������

    3
   / \
  9  20
    /  \
   15   7

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
        
        //���������Ҹ�λ��
        int inRoot = inbegin;
        while(inRoot <= inend)
        {
            if(inorder[inRoot] == rootVal)
                break;
            ++inRoot;
        }
        
		// [inbegin, inRooti-1] inRooti [inRooti+1, inend] ������������[inbegin, inRooti-1] ������������[inRooti+1, inend]
        // ������������������ݹ鴴����������������������䲻���ڣ����������ǿ���
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