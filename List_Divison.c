/*��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ

����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
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