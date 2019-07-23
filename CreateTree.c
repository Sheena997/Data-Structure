/*编一个程序，读入用户输入的一串先序遍历字符串，
根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 
其中“#”表示的是空格，空格字符代表空树。
建立起此二叉树以后，再对二叉树进行中序遍历，
输出遍历结果。*/
#include <stdio.h>
#include <malloc.h>

typedef struct TreeNode
{
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;
Node* CreateTree(char *s, int *pi)
{
	if (s[*pi] == '#')
		return NULL;
	Node *node = (Node*)malloc(sizeof(Node));
	node->val = s[*pi];
	++(*pi);
	node->left = CreateTree(s, pi);
	++(*pi);
	node->right = CreateTree(s, pi);
	return node;
}
void InorderTree(Node* t)
{
	if (t == NULL)
		return;
	InorderTree(t->left);
	printf("%c ", t->val);
	InorderTree(t->right);
}
int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	Node *p = CreateTree(str, &i);
	InorderTree(p);

	return 0;
}