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
		//ʹ�ÿ���ָ��fast��slow��fast����k����Ȼ��fast��slow����ͬ���ٶ�ͬ����һ����
		//��fast�ߵ����������һ�����ʱ��slowָ��ı��ǵ�����k����㡣
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