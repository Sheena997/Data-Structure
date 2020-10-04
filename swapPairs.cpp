/*
24. �������������еĽڵ�
����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ��:
���� 1->2->3->4, ��Ӧ�÷��� 2->1->4->3.

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* cur = head->next;
        ListNode* pre = head;
        
        while(cur)
        {
            swap(cur->val, pre->val);
            if(cur->next == nullptr)
                break;
            cur = cur->next->next;
            pre = pre->next->next;
        }
        
        return head;
    }
};


//�ݹ�
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return nullptr;
        
        ListNode* cur = head->next;
        if(!cur)
            return head;
        
        ListNode* node = cur->next;
        cur->next = head;
        head->next = swapPairs(node);
        
        return cur;
    }
};