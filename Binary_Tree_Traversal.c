//先序遍历
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void _preorderTraversal(struct TreeNode* root, int *a, int *pi)
{
	if (root == NULL)
		return;
	a[*pi] = root->val;
	++(*pi);
	_preorderTraversal(root->left, a, pi);
	_preorderTraversal(root->right, a, pi);
}
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int *array = malloc(*returnSize * sizeof(int));
	int i = 0;
	_preorderTraversal(root, array, &i);
	return array;
}


//中序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _inorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
		return 0;
	_inorderTraversal(root->left, a, pi);
	a[*pi] = root->val;
	++(*pi);
	_inorderTraversal(root->right, a, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int *array = malloc(*returnSize*(sizeof(int)));
	int i = 0;
	_inorderTraversal(root, array, &i);
	return array;
}



//后序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _postorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
		return 0;
	_postorderTraversal(root->left, a, pi);
	_postorderTraversal(root->right, a, pi);
	a[*pi] = root->val;
	++(*pi);
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int *array = malloc(*returnSize * sizeof(int));
	int i = 0;
	_postorderTraversal(root, array, &i);
	return array;
}

