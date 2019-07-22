/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		//使用快慢指针fast和slow，fast先走k步，然后fast和slow按照同样速度同样走一步，
		//当fast走到单链表最后一个结点时，slow指向的便是倒数第k个结点。
		ListNode *fast = pListHead;
		ListNode *slow = pListHead;
		for (int i = 0; i< k; i++)
		{
			if (fast == NULL)
				return NULL;
			fast = fast->next;
		}
		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};