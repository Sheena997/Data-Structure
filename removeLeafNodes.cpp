/*
1325. ɾ������ֵ��Ҷ�ӽڵ�
����һ���� root Ϊ���Ķ�������һ������ target ������ɾ������ֵΪ target �� Ҷ�ӽڵ� ��
ע�⣬һ��ɾ��ֵΪ target ��Ҷ�ӽڵ㣬���ĸ��ڵ�Ϳ��ܱ��Ҷ�ӽڵ㣻�����Ҷ�ӽڵ��ֵ
ǡ��Ҳ�� target ����ô����ڵ�ҲӦ�ñ�ɾ����Ҳ����˵������Ҫ�ظ��˹���ֱ�����ܼ���ɾ����

ʾ�� 1��
���룺root = [1,2,3,2,null,2,4], target = 2
�����[1,null,3,null,4]
���ͣ�
������ߵ�ͼ�У���ɫ�ڵ�ΪҶ�ӽڵ㣬�����ǵ�ֵ�� target ��ͬ��ͬΪ 2 �������ǻᱻɾ�����õ��м��ͼ��
��һ���µĽڵ�����Ҷ�ӽڵ�������ֵ�� target ��ͬ�����Խ��ٴν���ɾ�����Ӷ��õ����ұߵ�ͼ��

ʾ�� 2��
���룺root = [1,3,3,3,2], target = 3
�����[1,3,null,null,2]

ʾ�� 3��
���룺root = [1,2,null,2,null,2], target = 2
�����[1]
���ͣ�ÿһ����ɾ��һ����ɫ��Ҷ�ӽڵ㣨ֵΪ 2����

ʾ�� 4��
���룺root = [1,1,1], target = 1
�����[]

ʾ�� 5��
���룺root = [1,2,3], target = 1
�����[1,2,3]
 

��ʾ��
1 <= target <= 1000
ÿһ��������� 3000 ���ڵ㡣
ÿһ���ڵ�ֵ�ķ�Χ�� [1, 1000] ��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/delete-leaves-with-a-given-value/
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == nullptr)
            return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(root->left == nullptr && root->right == nullptr && root->val == target)
            return nullptr;
        
        return root;
    }
};