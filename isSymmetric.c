/*给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool _isSymmetric(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;
	if (s->val != t->val)
		return false;
	return _isSymmetric(s->left, t->right) && _isSymmetric(s->right, t->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}

