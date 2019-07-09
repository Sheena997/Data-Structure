//删除单链表中等于给定值val的所有节点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode *cur = head;
	struct ListNode *prev = NULL;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			struct ListNode *next = cur->next;
			free(cur);
			if (prev == NULL)
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}

