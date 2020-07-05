/*
328. 奇偶链表
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，
而不是节点的值的奇偶性。
请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

来源：LeetCode
链接：https://leetcode-cn.com/problems/odd-even-linked-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *head1, *head2, *tail1, *tail2;
        head1 = tail1 = new ListNode();
        head2 = tail2 = new ListNode();
        int i = 1;
        while(head != NULL)
        {
            if( i & 1 == 1)
            {
                tail1->next = head;
                tail1 = tail1->next;
            } 
            else
            {
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = head->next;
            ++i;
        }
        tail2->next = NULL;
        tail1->next = head2->next;
        return head1->next;
    }
};


//评论：O(1)的空间复杂度
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* odd = head, *even = head->next, *evenHead = even;
        while(even && even->next)
        {
            //奇数节点链接偶数节点的next节点，同时更新偶数节点
            odd->next = even->next;
            odd = odd->next;
            //偶数节点链接奇数节点的next节点，同时更新奇数节点
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
    }
};