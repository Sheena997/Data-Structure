/*
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
�����1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������
6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6����������
������3���ڵ���ֵΪ4�Ľڵ㡣
ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* p = head;
        while(p)
        {
            res.push_back(p);
            p = p -> next;
        }
        
        return res[res.size() - k];
            
    }
};