/*
147. ��������в�������
��������в�������

ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�

���������㷨��
���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
�ظ�ֱ�������������ݲ�����Ϊֹ��
 

ʾ�� 1��
����: 4->2->1->3
���: 1->2->3->4

ʾ�� 2��
����: -1->5->3->4->0
���: -1->0->3->4->5

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* resList = new ListNode(INT_MIN);
        ListNode* cur = head;
        
        while(cur)
        {
            ListNode* tmp = resList;
            ListNode* last = nullptr;
            
            while(tmp != nullptr && cur->val >= tmp->val)
            {
                last = tmp;
                tmp = tmp->next;
            }
            
            last->next = cur;
            cur = cur->next;
            last->next->next = tmp;
        }
        
        return resList->next;
    }
};