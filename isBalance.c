//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int TreeHeight(struct TreeNode* s)
{
	if (s == NULL)
		return 0;
	int leftheight = TreeHeight(s->left);
	int rightheight = TreeHeight(s->right);
	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}
bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;
	int left = TreeHeight(root->left);
	int right = TreeHeight(root->right);
	return abs(left - right) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}

