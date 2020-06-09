/*
445. ������� II
�������� �ǿ� ���������������Ǹ��������������λλ������ʼλ�á�
���ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
���ף�
��������������޸ĸ���δ������仰˵���㲻�ܶ��б��еĽڵ���з�ת��

ʾ����

���룺(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 8 -> 0 -> 7

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/add-two-numbers-ii/
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
        stack<int> sx, sy;
        while(l1)
        {
            sx.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            sy.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* node = nullptr;
        int ret = 0;
        while(!sx.empty() || !sy.empty() || ret > 0)
        {
            int sum = ret;
            if(!sx.empty())
            {
                sum += sx.top();
                sx.pop();
            }
            if(!sy.empty())
            {
                sum += sy.top();
                sy.pop();
            }
            ListNode* tmp = new ListNode(sum % 10);
            tmp->next = node;
            node = tmp;
            ret = sum / 10;
        }
        
        return node;
    }
};