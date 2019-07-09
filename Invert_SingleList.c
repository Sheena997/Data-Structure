



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode *n1 = head;
	struct ListNode *n2 = n1->next;
	struct ListNode *n3 = n2->next;
	head->next = NULL;
	while (n2 != NULL)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
			n3 = n3->next;
	}
	head = n1;
	return head;
}
