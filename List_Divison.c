/*编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
*/
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode *head1;
		ListNode *head2;
		ListNode *tail1;
		ListNode *tail2;
		head1 = tail1 = (ListNode*)malloc(sizeof(ListNode));
		head2 = tail2 = (ListNode*)malloc(sizeof(ListNode));
		while (pHead != NULL)
		{
			if (pHead->val < x)
			{
				tail1->next = pHead;
				tail1 = tail1->next;
			}
			else
			{
				tail2->next = pHead;
				tail2 = tail2->next;
			}
			pHead = pHead->next;
		}
		tail2->next = NULL;
		if (head1 == NULL)
			return head2->next;
		tail1->next = head2->next;
		return head1->next;
	}
};