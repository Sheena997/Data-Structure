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
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSametree(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	if (t1->val != t2->val)
		return false;
	return isSametree(t1->left, t2->left) && isSametree(t1->right, t2->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (s == NULL)
		return false;
	if (s->val == t->val)
	{
		if (isSametree(s, t))
			return true;
	}

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}

