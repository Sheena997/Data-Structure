/*����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��

����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900
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
        //��ѯ���м���
        /*ListNode *slow = A;
        ListNode *fast = A;
        while (fast)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *m = slow;
        //���ú�������
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