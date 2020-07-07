/*
������ 02.05. �������
���������������ʾ��������ÿ���ڵ����һ����λ��

��Щ��λ�Ƿ����ŵģ�Ҳ���Ǹ�λ���������ײ���

��д������������������ͣ�����������ʽ���ؽ����

 

ʾ����

���룺(7 -> 1 -> 6) + (5 -> 9 -> 2)����617 + 295
�����2 -> 1 -> 9����912
���ף�������Щ��λ�������ŵģ�������һ�顣

ʾ����

���룺(6 -> 1 -> 7) + (2 -> 9 -> 5)����617 + 295
�����9 -> 1 -> 2����912

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/sum-lists-lcci/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> s1, s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head, *tail;
        head = tail = new ListNode;
        int ret = 0;
        
        while(!s1.empty() || !s2.empty() || ret > 0)
        {
            int sum = ret;
            if(!s1.empty())
            {
                sum += s1.front();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum += s2.front();
                s2.pop();
            }
            
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            ret = sum / 10;
        }
        
        return head->next;
    }
};