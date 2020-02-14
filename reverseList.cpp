/*
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
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
            swap(p, head->next);//交换指针指向的结点
        
        return p;
    }
};