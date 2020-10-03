/*
147. 对链表进行插入排序
对链表进行插入排序。

每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：
输入: 4->2->1->3
输出: 1->2->3->4

示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：LeetCode
链接：https://leetcode-cn.com/problems/insertion-sort-list/
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