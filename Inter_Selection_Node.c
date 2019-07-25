//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0;
	int lenB = 0;
	struct ListNode *a = headA;
	struct ListNode *b = headB;
	while (a)
	{
		++lenA;
		a = a->next;
	}
	while (b)
	{
		++lenB;
		b = b->next;
	}
	struct ListNode* LongList = headA;
	struct ListNode* ShortList = headB;
	if (lenA < lenB)
	{
		LongList = headB;
		ShortList = headA;
	}
	int m = abs(lenA - lenB);
	while (m--)
	{
		LongList = LongList->next;
	}
	while (LongList != ShortList)
	{
		LongList = LongList->next;
		ShortList = ShortList->next;
	}
	return LongList;
}