/*
951. ��ת�ȼ۶�����
���ǿ���Ϊ������ T ����һ����ת������������ʾ��ѡ������ڵ㣬Ȼ�󽻻���������������������
ֻҪ����һ�������ķ�ת��������ʹ X ���� Y�����Ǿͳƶ����� X ��ת�ȼ��ڶ����� Y��
��дһ���ж������������Ƿ��Ƿ�ת�ȼ۵ĺ�������Щ���ɸ��ڵ� root1 �� root2 ������

ʾ����
���룺root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
�����true
���ͣ����Ƿ�תֵΪ 1��3 �Լ� 5 �������ڵ㡣
Flipped Trees Diagram

��ʾ��
ÿ��������� 100 ���ڵ㡣
ÿ�����е�ÿ��ֵ����Ψһ�ġ��� [0, 99] ��Χ�ڵ�������

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/flip-equivalent-binary-trees/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        
        if(root1 == nullptr || root2 == nullptr)
            return false;
        
        if(root1->val == root2->val)
            return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
                || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        
        return false;
    }
};