/*
445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
进阶：
如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7

来源：LeetCode
链接：https://leetcode-cn.com/problems/add-two-numbers-ii/
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