/*
��תһ��������
ʾ��:
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-linked-list
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p;
        for(p = NULL; head != NULL; swap(head, p))
            swap(p, head->next);//����ָ��ָ��Ľ��
        
        return p;
    }
};