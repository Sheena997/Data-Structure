/*对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。

给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        //查询到中间结点
        /*ListNode *slow = A;
        ListNode *fast = A;
        while (fast)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *m = slow;
        //逆置后半段链表
        ListNode *head = NULL;
        while (m)
        {
            
        }*/

        ListNode *cur = A;
        int i = 0;
        int n = 0;
        int a[900] = { 0 };
        while (cur != NULL)
        {
            a[i++] = cur->val;
            ++n;
            cur = cur->next;
        }
        int left = 0;
        int right = n-1;
        while (left < right)
        {
            if(a[left] != a[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};