/*
148. 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。


示例 1:
输入: 4->2->1->3
输出: 1->2->3->4

示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：LeetCode
链接：https://leetcode-cn.com/problems/sort-list/
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
    ListNode* _mergeSort(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = _mergeSort(l1->next, l2);
            
            return l1;
        }
        else
        {
            l2->next = _mergeSort(l2->next, l1);
            
            return l2;
        }
    }
    ListNode* mergeSort(ListNode* node)
    {
        if(!node || !node->next)
            return node;
        
        ListNode* fast = node, *slow = node, *last = node;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            last = slow;
            slow = slow->next;
        }
        
        last->next = nullptr;
        
        ListNode* l1 = mergeSort(node);
        ListNode* l2 = mergeSort(slow);
        
        return _mergeSort(l1, l2);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};