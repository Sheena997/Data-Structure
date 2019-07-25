//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//https://leetcode-cn.com/problems/linked-list-cycle-ii/description/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* hasCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return slow;
	}
	return NULL;
}
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* snode = hasCycle(head);
	if (snode == NULL)
		return NULL;
	while (snode != head)
	{
		head = head->next;
		snode = snode->next;
	}
	return snode;
}