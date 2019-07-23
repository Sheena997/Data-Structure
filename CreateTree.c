/*��һ�����򣬶����û������һ����������ַ�����
���ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
�������µ���������ַ����� ABC##DE#G##F### 
���С�#����ʾ���ǿո񣬿ո��ַ����������
������˶������Ժ��ٶԶ������������������
������������*/
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