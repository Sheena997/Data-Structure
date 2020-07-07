/*
面试题 02.05. 链表求和
给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。

 

示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
进阶：假设这些数位是正向存放的，请再做一遍。

示例：

输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912

来源：LeetCode
链接：https://leetcode-cn.com/problems/sum-lists-lcci/
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