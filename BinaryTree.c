#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TreeNode
{
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;
//前序遍历来创建二叉树
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

//二叉树的销毁
void BinaryTreeDestroy(Node* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
	root = NULL;
}

//叶子结点数目
int BinaryTreeLeafSize(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//求第k层结点总共的个数
int BinaryTreeLevelKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

//寻找值为x的结点
Node* BinaryTreeFind(Node* root, char x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	Node *lret = BinaryTreeFind(root->left, x);
	Node *rret = BinaryTreeFind(root->right, x);
	if (lret != NULL)
		return lret;
	else if (rret != NULL)
		return rret;
	return NULL;
}

//中序遍历
void InorderTree(Node* t)
{
	if (t == NULL)
		return;
	InorderTree(t->left);
	printf("%c ", t->val);
	InorderTree(t->right);
}

//层序遍历
typedef char* QUDataType;
typedef struct QueueNode
{
	struct QueueNode *_next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode *_front;
	QueueNode *_rear;
}Queue;

void QueueInit(Queue *pq);
void QueueDestory(Queue *pq);

QueueNode* BuyQueueNode(QUDataType x);

void QueuePush(Queue *pq, QUDataType x);
void QueuePop(Queue *pq);
QUDataType QueueFront(Queue *pq);
bool QueueEmpty(Queue *pq);



void QueueInit(Queue *pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}

void QueueDestory(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_front;
	while (cur)
	{
		QueueNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}


QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue *pq, QUDataType x)
{
	assert(pq);
	QueueNode *newnode = BuyQueueNode(x);
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = newnode;
	}
	else
	{
		pq->_rear->_next = newnode;
		pq->_rear = newnode;
	}
}
void QueuePop(Queue *pq)
{
	assert(pq && pq->_front != NULL);
	QueueNode *next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;
}
QUDataType QueueFront(Queue *pq)
{
	assert(pq && pq->_front != NULL);;
	return pq->_front->_data;
}

bool QueueEmpty(Queue *pq)
{
	assert(pq);
	return pq->_front == NULL;
}

void BinaryTreeLevelOrder(Node* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		Node *front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->val);
		if (front->left)
		QueuePush(&q, front->left);
		if (front->right)
		QueuePush(&q, front->right);
	}
	printf("\n");
}

//判断二叉树是否为完全二叉树
bool BinaryTreeComplete(Node* root)
{
	Queue q;
	QueueInit(&q);
	
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		Node *front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		Node *front = QueueFront(&q);
		if (front != NULL)
		{
			QueueDestory(&q);
			return false;
		}
	}
	return true;
}


int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	Node *p = CreateTree(str, &i);
	InorderTree(p);
	printf("\n");
	printf("%d\n", BinaryTreeLevelKSize(p, 2));
	printf("%d\n", BinaryTreeLeafSize(p));
	BinaryTreeLevelOrder(p);
	if (BinaryTreeComplete(p))
		printf("true!\n");
	else
		printf("false!\n");
	system("pause");
	return 0;
}

