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
        queue<int> q1, q2;
        while(l1)
        {
            q1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            q2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head, *tail;
        head = tail = new ListNode;
        int ret = 0;
        
        while(!q1.empty() || !q2.empty() || ret > 0)
        {
            int sum = ret;
            if(!q1.empty())
            {
                sum += q1.front();
                q1.pop();
            }
            if(!q2.empty())
            {
                sum += q2.front();
                q2.pop();
            }
            
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            ret = sum / 10;
        }
        
        return head->next;
    }
};