/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int maxleft = maxDepth(root->left);
	int maxright = maxDepth(root->right);
	return maxleft > maxright ? (maxleft + 1) : (maxright + 1);
}

