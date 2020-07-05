/*
328. ��ż����
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ�
�����ǽڵ��ֵ����ż�ԡ�
�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:

����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:

����: 2->1->3->5->6->4->7->NULL 
���: 2->3->6->7->1->5->4->NULL
˵��:

Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/odd-even-linked-list/
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


//���ۣ�O(1)�Ŀռ临�Ӷ�
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
            //�����ڵ�����ż���ڵ��next�ڵ㣬ͬʱ����ż���ڵ�
            odd->next = even->next;
            odd = odd->next;
            //ż���ڵ����������ڵ��next�ڵ㣬ͬʱ���������ڵ�
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
    }
};